#include "TableData.h"

const SharedPtr TableData::NullValue{nullptr};

void TableData::deleteInteger(SharedPtr& ptr) noexcept {
    ptr.release<TableTypes::Integer>();
}

void TableData::deleteString(SharedPtr& ptr) noexcept {
    ptr.release<TableTypes::String>();
}

template<>
SharedPtr::Deleter TableData::deleterFor<TableTypes::Integer>() noexcept {
    return deleteInteger;
}

template<>
SharedPtr::Deleter TableData::deleterFor<TableTypes::String>() noexcept {
    return deleteString;
}

TableData::TableData() noexcept
: data{}, columns{0} { }


TableTypes::Row TableData::rowsCount() const noexcept {
    return columns == 0 ? 0 : (data.size() / columns);
}

TableTypes::Column TableData::columnsCount() const noexcept {
    return columns;
}

void TableData::addColumn() {
    const TableTypes::Row rows = rowsCount();
    if(rows > 0) {
        const size_t oldSize = data.size();
        DynamicArray<SharedPtr> newData{oldSize + data.unused() + rows};
        for(size_t index = 1; index <= oldSize; ++index) {
            newData.push(data[index - 1]);
            if((index % columns) == 0) {
                newData.push(NullValue);
            }
        }
        data = std::move(newData);
    }
    ++columns;
}

template<typename Type>
TableData::FindFirstResult TableData::findFirstInColumn(TableTypes::Column column, const Type& value) noexcept {
    const size_t size = data.size();
    for(size_t index = column; index < size; index += columns) {
        SharedPtr& ptr = data[index];
        if(!ptr.isNullPtr() && (ptr.getConstRef<Type>() == value)) {
            return {ptr, index};
        }
    }
    return {const_cast<SharedPtr&>(NullValue), size};
}

template<typename Type>
SharedPtr TableData::obtainSharedPtrForValueInColumn(TableTypes::Column column, Type&& value) {
    const FindFirstResult found = findFirstInColumn<Type>(column, value);
    if(found.shared.isNullPtr()) {
        return {std::move(value), deleterFor<Type>()};
    }
    return found.shared;
}

template<typename Type>
void TableData::insertValue(Type&& value) {
    if(columns > 0) {
        data.push(obtainSharedPtrForValueInColumn<Type>(data.size() % columns, std::move(value)));
    }
}

void TableData::insert(TableTypes::Integer&& value) {
    insertValue<TableTypes::Integer>(std::move(value));
}

void TableData::insert(TableTypes::String&& value) {
    insertValue<TableTypes::String>(std::move(value));
}

size_t TableData::calculateIndexFor(TableTypes::Row row, TableTypes::Column column) const noexcept {
    return static_cast<size_t>(row) * static_cast<size_t>(columns) + static_cast<size_t>(column);
}

const SharedPtr& TableData::operator()(TableTypes::Row row, TableTypes::Column column) const noexcept {
    const size_t index = calculateIndexFor(row, column);
    if((data.size() > index) && (rowsCount() > row) && (columns > column)) {
        return data[index];
    }
    return NullValue;
}

const SharedPtr& TableData::get(TableTypes::Row row, TableTypes::Column column) const noexcept {
    return operator()(row, column);
}

RowsFilterResult TableData::selectAllRows() const noexcept {
    return RowsFilterResult::allRows(rowsCount());
}

TableTypes::Row TableData::calculateRowFor(size_t index) const noexcept {
    return  index / columns;
}

RowsFilterResult TableData::selectRowsMatching(TableTypes::Column column, std::nullptr_t) const {
    const size_t size = data.size();
    RowsFilterResult result;
    for(size_t index = column; index < size; index += columns) {
        if(data[index].isNullPtr()) {
            if(result.isEmpty()) {
                result = std::move(RowsFilterResult{rowsCount()});
            }
            result.addRow(calculateRowFor(index));
        }
    }
    result.optimize();
    return result;
}

RowsFilterResult TableData::selectRowsMatching(TableTypes::Column column, TableTypes::Integer value) const {
    return selectRowsMatchingValueInColumn<TableTypes::Integer>(column, value);
}

RowsFilterResult TableData::selectRowsMatching(TableTypes::Column column, const TableTypes::String& value) const {
    return selectRowsMatchingValueInColumn<TableTypes::String>(column, value);
}

void TableData::updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, std::nullptr_t) {
    const size_t count = filteredRows.count();
    for(size_t index = 0; index < count; ++index) {
        data[calculateIndexFor(filteredRows[index], column)] = nullptr;
    }
}

template<typename Type>
RowsFilterResult TableData::selectRowsMatchingValueInColumn(TableTypes::Column column, const Type& value) const {
    const FindFirstResult found = const_cast<TableData* const>(this)->findFirstInColumn<Type>(column, value);
    if(!found.shared.isNullPtr()) {
        const size_t size = data.size();
        RowsFilterResult result{rowsCount()};
        result.addRow(calculateRowFor(found.index));
        for(size_t index = found.index + columns; index < size; index += columns) {
            if(found.shared == data[index]) {
                result.addRow(calculateRowFor(index));
            }
        }
        result.optimize();
        return result;
    }
    return {};
}

template<typename Type>
void TableData::updateRowsColumn(const RowsFilterResult& filteredRows, TableTypes::Column column, Type&& value) {
    if(!filteredRows.isEmpty()) {
        const SharedPtr& newValue = obtainSharedPtrForValueInColumn<Type>(column, std::move(value));
        const size_t count = filteredRows.count();
        for(size_t index = 0; index < count; ++index) {
            data[calculateIndexFor(filteredRows[index], column)] = newValue;
        }
    }
}

void TableData::updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, TableTypes::Integer&& value) {
    updateRowsColumn<TableTypes::Integer>(filteredRows, column, std::move(value));
}

void TableData::updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, TableTypes::String&& value){
    updateRowsColumn<TableTypes::String>(filteredRows, column, std::move(value));
}