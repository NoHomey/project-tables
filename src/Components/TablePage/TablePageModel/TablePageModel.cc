#include "TablePageModel.h"

TablePageModel::TablePageModel(const Table& table, RowsFilterResult&& filteredRows) noexcept
: table{table}, tableData{table.data()}, filteredRows{std::move(filteredRows)} { }

TableTypes::Row TablePageModel::rowsCount() const noexcept {
    return filteredRows.count();
}

TableTypes::Column TablePageModel::columnsCount() const noexcept {
    return tableData.columnsCount();
}

ColumnMetaData::ColumnType TablePageModel::columnType(TableTypes::Column column) const noexcept {
    return table.getColumnsMetaData()[column].getType();
}

const SharedPtr& TablePageModel::operator()(TableTypes::Row row, TableTypes::Column column) const noexcept {
    return tableData(filteredRows[row], column);
}

TableTypes::Row TablePageModel::tableRowNumber(TableTypes::Row row) const noexcept {
    return filteredRows[row] + 1;
}