#include "TableSaved.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString TableSaved::textBeginning{"Query result: successfully saved Table '"};

ConstString TableSaved::textAfterTableName{"' to file: "};

const size_t TableSaved::ownTextLength = textAfterTableName.length();

TableSaved::TableSaved(const FixedSizeString& tableName, ConstString& fileName)
: MessageContainingTableName<ImmutableString>{tableName, ownTextLength + fileName.length()},
fileName{FixedSizeString::fromString(fileName)} { }

void TableSaved::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textAfterTableName);
    TypesOutputer::output(outputStream, fileName);
}