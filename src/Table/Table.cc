#include "Table.h"
#include <utility>

Table::Table(FixedSizeString&& name)
: name{std::move(name)}, columnsMetaData{}, tableData{} { }

const FixedSizeString& Table::getName() const noexcept {
    return name;
}

const DynamicArray<ColumnMetaData>& Table::getColumnsMetaData() const noexcept {
    return columnsMetaData;
}

void Table::addColumn(const ColumnMetaData& metaData) {
    columnsMetaData.push(metaData);
    tableData.addColumn();
}

void Table::rename(FixedSizeString&& newName) noexcept {
    name = std::move(newName);
}