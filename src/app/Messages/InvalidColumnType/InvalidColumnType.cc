#include "InvalidColumnType.h"
#include "../../../TypesOutputer/TypesOutputer.h"

InvalidColumnType InvalidColumnType::instance;

ConstString InvalidColumnType::textBeginning{"Parse Error: '"};

ConstString InvalidColumnType::textEnding{"' is invalid column type identificator. Valid column type identificators are 'Integer', 'FractionalNumber' and 'String'."};

const size_t InvalidColumnType::ownTextLength = textBeginning.length() + textEnding.length();

InvalidColumnType* InvalidColumnType::inject(const String& argument) {
    instance.argument = FixedSizeString::fromString(argument);
    instance.setTextLength(ownTextLength + argument.length());
    return &instance;
}

void InvalidColumnType::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, argument);
    TypesOutputer::output(outputStream, textEnding);
}

void InvalidColumnType::releaseResources() noexcept {
    argument = {};
}