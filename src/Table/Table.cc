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

FixedSizeString Table::rename(FixedSizeString&& newName) noexcept {
    FixedSizeString oldName = std::move(name);
    name = std::move(newName);
    return oldName;
}

TableData& Table::data() noexcept {
    return tableData;
}

const TableData& Table::data() const noexcept {
    return tableData;
}