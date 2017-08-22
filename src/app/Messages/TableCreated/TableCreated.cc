#include "TableCreated.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString TableCreated::textBeginning{"Query result: successfully created Table '"};

ConstString TableCreated::textEnding{"'."};

const size_t TableCreated::ownTextLength = textBeginning.length() + textEnding.length();

TableCreated::TableCreated(const FixedSizeString& tableName) noexcept
: MessageContainingTableName<ImmutableString>{tableName, ownTextLength} { }

void TableCreated::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}