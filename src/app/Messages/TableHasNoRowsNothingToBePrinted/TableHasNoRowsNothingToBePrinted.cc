#include "TableHasNoRowsNothingToBePrinted.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString TableHasNoRowsNothingToBePrinted::textRows{"rows"};

TableHasNoRowsNothingToBePrinted::TableHasNoRowsNothingToBePrinted(const FixedSizeString& tableName) noexcept
:  TableHasNoNothingToBePrinted{tableName, textRows} { }
