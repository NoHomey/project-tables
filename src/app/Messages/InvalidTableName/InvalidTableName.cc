#include "InvalidTableName.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../TypesOutputer/TypesOutputer.h"

InvalidTableName InvalidTableName::instance;

ConstString InvalidTableName::textBeginning{"Parse Error: '"};

ConstString InvalidTableName::textEnding{"' is invalid table name identificator. Valid table name identificator begins with a letter and can have: letter, digit, '_', '#' or '$' for any subsequent symbol."};

const size_t InvalidTableName::ownTextLength = textBeginning.length() + textEnding.length();

InvalidTableName* InvalidTableName::inject(const String& tableName) {
    instance.setTableName(tableName);
    return &instance;
}

size_t InvalidTableName::textLength() const noexcept {
    return ownTextLength + tableName.length();
}

void InvalidTableName::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}