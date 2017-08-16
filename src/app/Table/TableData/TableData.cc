#include "TableData.h"

const SharedPtr TableData::NullValue{nullptr};

void TableData::deleteInteger(SharedPtr& ptr) noexcept {
    ptr.release<TableTypes::Integer>();
}

void TableData::deleteString(SharedPtr& ptr) noexcept {
    ptr.release<TableTypes::String>();
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
        DynamicArray<SharedPtr> newData{oldSize + rows + 2 * (columns + 1)};
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
SharedPtr TableData::obtainSharedPtrForValueInColumn(TableTypes::Column column, Type&& value, SharedPtr::Deleter deleter) {
    const FindFirstResult found = findFirstInColumn<Type>(column, value);
    if(found.shared.isNullPtr()) {
        return {std::move(value), deleter};
    }
    return found.shared;
}

template<typename Type>
void TableData::insert(Type&& value, SharedPtr::Deleter deleter) {
    if(columns > 0) {
        data.push(obtainSharedPtrForValueInColumn<Type>(data.size() % columns, std::move(value), deleter));
    }
}

void TableData::insert(TableTypes::Integer&& value) {
    insert<TableTypes::Integer>(std::move(value), deleteInteger);
}

void TableData::insert(TableTypes::String&& value) {
    insert<TableTypes::String>(std::move(value), deleteString);
}

const SharedPtr& TableData::operator()(TableTypes::Row row, TableTypes::Column column) const noexcept {
    const size_t index = static_cast<size_t>(row) * static_cast<size_t>(columns) + static_cast<size_t>(column);
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

RowsFilterResult TableData::selectRowsMatching(TableTypes::Column column, std::nullptr_t) const noexcept {
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

RowsFilterResult TableData::selectRowsMatching(TableTypes::Column column, TableTypes::Integer value) const noexcept {
    return selectRowsMatchingValueInColumn<TableTypes::Integer>(column, value);
}

RowsFilterResult TableData::selectRowsMatching(TableTypes::Column column, const TableTypes::String& value) const noexcept {
    return selectRowsMatchingValueInColumn<TableTypes::String>(column, value);
}

template<typename Type>
RowsFilterResult TableData::selectRowsMatchingValueInColumn(TableTypes::Column column, const Type& value) const noexcept {
    const FindFirstResult found = const_cast<TableData* const>(this)->findFirstInColumn<Type>(column, value);
    if(!found.shared.isNullPtr()) {
        const size_t size = data.size();
        RowsFilterResult result{rowsCount()};
        result.addRow(found.index);
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