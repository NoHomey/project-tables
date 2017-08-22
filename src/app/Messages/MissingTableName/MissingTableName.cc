#include "MissingTableName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingTableName::tableNameIdentificator{"table name identificator"};

MissingTableName::MissingTableName(ConstString& command, unsigned int argument) noexcept
: MissingArgument{tableNameIdentificator, command, argument} { }