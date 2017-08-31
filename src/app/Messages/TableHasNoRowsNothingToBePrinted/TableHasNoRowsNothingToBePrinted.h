#pragma once

#include "../TableHasNoNothingToBePrinted/TableHasNoNothingToBePrinted.h"

class TableHasNoRowsNothingToBePrinted: public TableHasNoNothingToBePrinted {
public:
    TableHasNoRowsNothingToBePrinted(const FixedSizeString& tableName) noexcept;

    TableHasNoRowsNothingToBePrinted(const TableHasNoRowsNothingToBePrinted& other) = delete;

    TableHasNoRowsNothingToBePrinted(TableHasNoRowsNothingToBePrinted&& other) = delete;

    TableHasNoRowsNothingToBePrinted& operator=(const TableHasNoRowsNothingToBePrinted& other) = delete;

    TableHasNoRowsNothingToBePrinted& operator=(TableHasNoRowsNothingToBePrinted&& other) = delete;
    
private:
    static ConstString textRows;
};