#include "Table.h"
#include <utility>

Table::Table(FixedSizeString&& name)
: name{std::move(name)} { }

const FixedSizeString& Table::getName() const noexcept {
    return name;
}

const DynamicArray<ColumnMetaData>& Table::getColumnsMetaData() const noexcept {
    return columnsMetaData;
}

void Table::addColumn(const ColumnMetaData& metaData) {
    columnsMetaData.push(metaData);
}

void Table::rename(FixedSizeString&& newName) noexcept {
    name = std::move(newName);
}