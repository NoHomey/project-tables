#include "MissingColumnNumber.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingColumnNumber::fileNameArgument{"Column number"};

MissingColumnNumber::MissingColumnNumber(ConstString& command, unsigned int argument) noexcept
: MissingArgument{fileNameArgument, command, argument} { }
