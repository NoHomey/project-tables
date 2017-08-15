#include "TableData.h"

const SharedPtr TableData::NullValue{nullptr};

void TableData::deleteInteger(SharedPtr& ptr) noexcept {
    ptr.release<Integer>();
}

void TableData::deleteFixedSizeString(SharedPtr& ptr) noexcept {
    ptr.release<FixedSizeString>();
}

TableData::TableData() noexcept
: data{}, columns{0} { }


TableData::Row TableData::rowsCount() const noexcept {
    return columns == 0 ? 0 : (data.size() / columns);
}

TableData::Column TableData::columnsCount() const noexcept {
    return columns;
}

void TableData::addColumn() {
    const Row rows = rowsCount();
    if(rows > 0) {
        const size_t oldSize = data.size();
        size_t newIndex = oldSize + rows - 1;
        data.fill(rows);
        for(size_t index = oldSize; index > columns; --index) {
            if((index % columns) == 0) {
                data[newIndex] = nullptr;
                --newIndex;
            }
            data[newIndex] = data[index - 1];
            --newIndex;
        }
        data[columns] = nullptr;
    }
    ++columns;
}

template<typename Type>
SharedPtr& TableData::findFirstInColumn(Column column, const Type& value) noexcept {
    const size_t size = data.size();
    for(size_t index = column; index < size; index += columns) {
        SharedPtr& ptr = data[index];
        if(!ptr.isNullPtr() && (ptr.getConstRef<Type>() == value)) {
            return ptr;
        }
    }
    return const_cast<SharedPtr&>(NullValue);
}

template<typename Type>
void TableData::insert(Type&& value, SharedPtr::Deleter deleter) {
    if(columns > 0) {
        const SharedPtr& found = findFirstInColumn(data.size() % columns, value);
        if(found.isNullPtr()) {
            data.push({std::move(value), deleter});
        } else {
            data.push(found);
        }
    }
}

void TableData::insert(Integer&& value) {
    insert<Integer>(std::move(value), deleteInteger);
}

void TableData::insert(FixedSizeString&& value) {
    insert<FixedSizeString>(std::move(value), deleteFixedSizeString);
}

const SharedPtr& TableData::operator()(Row row, Column column) const noexcept {
    const size_t index = static_cast<size_t>(row) * static_cast<size_t>(columns) + static_cast<size_t>(column);
    if((data.size() > index) && (rowsCount() > row) && (columns > column)) {
        return data[index];
    }
    return NullValue;
}

const SharedPtr& TableData::get(Row row, Column column) const noexcept {
    return operator()(row, column);
}