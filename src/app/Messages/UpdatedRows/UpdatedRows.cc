#include "UpdatedRows.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString UpdatedRows::textAction{"updated"};

UpdatedRows::UpdatedRows(TableTypes::Row rowsUpdated) noexcept
: RowsQueryResult{textAction, rowsUpdated} { }