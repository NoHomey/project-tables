#include "MissingFileName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingFileName::fileName{"file name"};

MissingFileName MissingFileName::instance;

MissingFileName::MissingFileName() noexcept
: MissingArgument{fileName} { }

MissingFileName* MissingFileName::inject(ConstString& command, ConstString& argument) noexcept {
    instance.set(command, argument);
    return &instance;
}