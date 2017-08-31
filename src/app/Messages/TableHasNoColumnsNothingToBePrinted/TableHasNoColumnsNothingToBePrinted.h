#pragma once

#include "../TableHasNoNothingToBePrinted/TableHasNoNothingToBePrinted.h"

class TableHasNoColumnsNothingToBePrinted: public TableHasNoNothingToBePrinted {
public:
    TableHasNoColumnsNothingToBePrinted(const FixedSizeString& tableName) noexcept;

    TableHasNoColumnsNothingToBePrinted(const TableHasNoColumnsNothingToBePrinted& other) = delete;

    TableHasNoColumnsNothingToBePrinted(TableHasNoColumnsNothingToBePrinted&& other) = delete;

    TableHasNoColumnsNothingToBePrinted& operator=(const TableHasNoColumnsNothingToBePrinted& other) = delete;

    TableHasNoColumnsNothingToBePrinted& operator=(TableHasNoColumnsNothingToBePrinted&& other) = delete;
    
private:
    static ConstString textColumns;
};