#include "CountedRows.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString CountedRows::textAction{"counted"};

CountedRows::CountedRows(TableTypes::Row rowsCounted) noexcept
: RowsQueryResult{textAction, rowsCounted} { }