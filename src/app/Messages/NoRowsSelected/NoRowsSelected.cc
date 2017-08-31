#include "NoRowsSelected.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString NoRowsSelected::textBeginning{"Query Result: Nothing to be printed. Either Table '"};

ConstString NoRowsSelected::textEnding{"' has no rows or no rows are found, matching the 'Select' query."};

const size_t NoRowsSelected::ownTextLength = textBeginning.length() + textEnding.length();

NoRowsSelected::NoRowsSelected(const FixedSizeString& tableName) noexcept
: MessageContainingTableName<ImmutableString>{tableName, ownTextLength} { }

void NoRowsSelected::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}