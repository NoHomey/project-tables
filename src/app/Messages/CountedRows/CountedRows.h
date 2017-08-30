#pragma once

#include "../RowsQueryResult/RowsQueryResult.h"

class CountedRows: public RowsQueryResult {
public:
    CountedRows(TableTypes::Row rowsCounted) noexcept;

    CountedRows(const CountedRows& other) = delete;

    CountedRows(CountedRows&& other) = delete;

    CountedRows& operator=(const CountedRows& other) = delete;

    CountedRows& operator=(CountedRows&& other) = delete;

private:
    static ConstString textAction;
};