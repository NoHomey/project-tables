#include "MissingFileName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingFileName::fileNameArgument{"file name"};

MissingFileName::MissingFileName(ConstString& command, unsigned int argument) noexcept
: MissingArgument{fileNameArgument, command, argument} { }
