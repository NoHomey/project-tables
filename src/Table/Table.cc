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

TableTypes::Column Table::columnsCount() const noexcept {
    return columnsMetaData.size();
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

const TableData& Table::data() const noexcept {
    return tableData;
}

RowsFilterResult Table::selectAllRows() const noexcept {
    return tableData.selectAllRows();
}

RowsFilterResult Table::selectRowsMatching(TableTypes::Column column, std::nullptr_t) const {
    return tableData.selectRowsMatching(column, nullptr);
}

RowsFilterResult Table::selectRowsMatching(TableTypes::Column column, const TableTypes::Integer& value) const {
    return tableData.selectRowsMatching(column, value);
}

RowsFilterResult Table::selectRowsMatching(TableTypes::Column column, const TableTypes::FractionalNumber& value) const{
    return tableData.selectRowsMatching(column, value);
}    

RowsFilterResult Table::selectRowsMatching(TableTypes::Column column, const TableTypes::String& value) const{
    return tableData.selectRowsMatching(column, value);
}

TableTypes::Row Table::countRowsMatching(TableTypes::Column column, std::nullptr_t) const{
    return selectRowsMatching(column, nullptr).count();
}

TableTypes::Row Table::countRowsMatching(TableTypes::Column column, const TableTypes::Integer& value) const {
    return selectRowsMatching(column, value).count();
}

TableTypes::Row Table::countRowsMatching(TableTypes::Column column, const TableTypes::FractionalNumber& value) const {
    return selectRowsMatching(column, value).count();
}

TableTypes::Row Table::countRowsMatching(TableTypes::Column column, const TableTypes::String& value) const {
    return selectRowsMatching(column, value).count();
}

void Table::insert(std::nullptr_t) {
    tableData.insert(nullptr);
}

void Table::insert(TableTypes::Integer&& value) {
    tableData.insert(std::move(value));
}

void Table::insert(TableTypes::FractionalNumber&& value) {
    tableData.insert(std::move(value));
}

void Table::insert(TableTypes::String&& value) {
    tableData.insert(std::move(value));
}

TableTypes::Row Table::deleteRowsMatching(TableTypes::Column column, std::nullptr_t) {
    const RowsFilterResult filter = selectRowsMatching(column, nullptr);
    tableData.deleteRows(filter);
    return filter.count();
}

TableTypes::Row Table::deleteRowsMatching(TableTypes::Column column, const TableTypes::Integer& value) {
    return deleteRowsMatchingAndReturnCount<TableTypes::Integer>(column, value);
}

TableTypes::Row Table::deleteRowsMatching(TableTypes::Column column, const TableTypes::FractionalNumber& value) {
    return deleteRowsMatchingAndReturnCount<TableTypes::FractionalNumber>(column, value);
}

TableTypes::Row Table::deleteRowsMatching(TableTypes::Column column, const TableTypes::String& value) {
    return deleteRowsMatchingAndReturnCount<TableTypes::String>(column, value);
}

template<typename Type>
TableTypes::Row Table::deleteRowsMatchingAndReturnCount(TableTypes::Column column, const Type& value) {
    const RowsFilterResult filter = selectRowsMatching(column, value);
    tableData.deleteRows(filter);
    return filter.count();
}