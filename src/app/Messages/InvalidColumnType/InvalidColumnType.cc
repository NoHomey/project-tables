#include "InvalidColumnType.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString InvalidColumnType::textBeginning{"Parse Error: '"};

ConstString InvalidColumnType::textEnding{"' is invalid column type identificator. Valid column type identificators are 'Integer', 'FractionalNumber' and 'String'."};

const size_t InvalidColumnType::ownTextLength = textBeginning.length() + textEnding.length();

InvalidColumnType::InvalidColumnType(const String& argument)
: InfoModel{argument.length() + ownTextLength, true},
argument{FixedSizeString::fromString(argument)} { }

void InvalidColumnType::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, argument);
    TypesOutputer::output(outputStream, textEnding);
}