#include "InvalidTableName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString InvalidTableName::textBeginning{"Parse Error: '"};

ConstString InvalidTableName::textEnding{"' is invalid table name identificator. Valid table name identificator begins with a letter and can have: letter, digit, '_', '#' or '$' for any subsequent symbol."};

const size_t InvalidTableName::ownTextLength = textBeginning.length() + textEnding.length();

InvalidTableName::InvalidTableName(const String& tableName)
: MessageContainingTableName<FixedSizeString>{tableName, ownTextLength} { }

void InvalidTableName::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}