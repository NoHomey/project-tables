#include "DeletedRows.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString DeletedRows::textAction{"deleted"};

DeletedRows::DeletedRows(TableTypes::Row rowsDeleted) noexcept
: RowsQueryResult{textAction, rowsDeleted} { }