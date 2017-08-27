#include "InsertedIntoTable.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString InsertedIntoTable::textBeginning{"Query result: successfully inserted new row into Table '"};

ConstString InsertedIntoTable::textEnding{"' ."};

const size_t InsertedIntoTable::ownTextLength = textEnding.length();

InsertedIntoTable::InsertedIntoTable(const FixedSizeString& tableName)
: MessageContainingTableName<ImmutableString>{tableName, ownTextLength} { }

void InsertedIntoTable::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}