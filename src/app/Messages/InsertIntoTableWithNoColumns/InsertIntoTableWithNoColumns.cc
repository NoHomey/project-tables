#include "InsertIntoTableWithNoColumns.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString InsertIntoTableWithNoColumns::textBeginning{"Insertation Error: inserting into Table '"};

ConstString InsertIntoTableWithNoColumns::textEnding{"' which has no columns."};

const size_t InsertIntoTableWithNoColumns::textLength = textBeginning.length() + textEnding.length();

InsertIntoTableWithNoColumns::InsertIntoTableWithNoColumns(const FixedSizeString& tableName) noexcept
: MessageContainingTableName<ImmutableString>{tableName, textLength} { }

void InsertIntoTableWithNoColumns::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}