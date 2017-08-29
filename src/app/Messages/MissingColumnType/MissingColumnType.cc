#include "MissingColumnType.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingColumnType::text{"Parse Error: Query command 'AddColumn' expects column type identificator as second argument. But none was found. Valid column type identificators are 'Integer', 'FractionalNumber' and 'String'."};

MissingColumnType MissingColumnType::instance;

MissingColumnType::MissingColumnType() noexcept
: InfoModel{text.length(), false} { }

MissingColumnType* MissingColumnType::missingColumnType() {
    return &instance;
}

void MissingColumnType::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
}