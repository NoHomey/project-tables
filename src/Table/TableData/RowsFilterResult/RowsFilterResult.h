#pragma once

#include "../../../Container/DynamicArray/DynamicArray.htd"
#include "../../TableTypes/TableTypes.h"

class RowsFilterResult {
public:
    static RowsFilterResult allRows(size_t all) noexcept;

public:
    RowsFilterResult() noexcept;

    RowsFilterResult(TableTypes::Row unFilteredRowsCount);

    RowsFilterResult(const RowsFilterResult& other) = delete;

    RowsFilterResult(RowsFilterResult&& other) noexcept = default;

    RowsFilterResult& operator=(const RowsFilterResult& other) = delete;
    
    RowsFilterResult& operator=(RowsFilterResult&& other) noexcept = default;

public:
    void addRow(TableTypes::Row row) noexcept;

    void optimize(TableTypes::Row rowsCount);

    size_t count() const noexcept;

    TableTypes::Row operator[](TableTypes::Row row) const noexcept;

    bool isEmpty() const noexcept;

private:
    RowsFilterResult(size_t allCount) noexcept;

private:
    static size_t calculateInitialCapacity(TableTypes::Row unFilteredRowsCount) noexcept;

private:
    static const size_t minUnused = 32;

private:
    size_t allCount;

    DynamicArray<TableTypes::Row> filteredRows;
};