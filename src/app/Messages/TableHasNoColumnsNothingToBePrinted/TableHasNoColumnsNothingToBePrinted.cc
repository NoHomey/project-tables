#include "TableHasNoColumnsNothingToBePrinted.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString TableHasNoColumnsNothingToBePrinted::textColumns{"columns"};

TableHasNoColumnsNothingToBePrinted::TableHasNoColumnsNothingToBePrinted(const FixedSizeString& tableName) noexcept
:  TableHasNoNothingToBePrinted{tableName, textColumns} { }
