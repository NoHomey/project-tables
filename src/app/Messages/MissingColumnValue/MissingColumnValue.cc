#include "MissingColumnValue.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingColumnValue::fileNameArgument{"Column Value"};

MissingColumnValue::MissingColumnValue(ConstString& command, unsigned int argument) noexcept
: MissingArgument{fileNameArgument, command, argument} { }