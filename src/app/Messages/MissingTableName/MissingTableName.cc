#include "MissingTableName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingTableName::tableNameIdentificator{"table name identificator"};

MissingTableName MissingTableName::instance;

MissingTableName::MissingTableName() noexcept
: MissingArgument{tableNameIdentificator} { }

MissingTableName* MissingTableName::inject(ConstString& command, ConstString& argument) noexcept {
    instance.set(command, argument);
    return &instance;
}