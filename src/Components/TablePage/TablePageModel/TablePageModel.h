#pragma once

#include "../../../Table/Table.h"

class TablePageModel {
public:
    TablePageModel(const Table& table, RowsFilterResult&& filteredRows) noexcept;

    TablePageModel(const TablePageModel& other) = delete;

    TablePageModel(TablePageModel&& other) = delete;

    TablePageModel& operator=(const TablePageModel& other) = delete;

    TablePageModel& operator=(TablePageModel&& other) = delete;

public:
    TableTypes::Row rowsCount() const noexcept;
    
    TableTypes::Column columnsCount() const noexcept;

    ColumnMetaData::ColumnType columnType(TableTypes::Column column) const noexcept;

    const SharedPtr& operator()(TableTypes::Row row, TableTypes::Column column) const noexcept;

private:
    const Table& table;

    const TableData& tableData;

    RowsFilterResult filteredRows;
};