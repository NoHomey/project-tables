#include "NewNameIsNotUnique.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString NewNameIsNotUnique::textBeginning{"Query Error: trying to rename Table '"};

ConstString NewNameIsNotUnique::textBetweenNames{"' to '"};

ConstString NewNameIsNotUnique::textNameIsNotUnique{"'. The new name is not unique. Table with name '"};

ConstString NewNameIsNotUnique::textEnding{"' already exists."};

const size_t NewNameIsNotUnique::ownTextLength = textBeginning.length()
    + textBetweenNames.length() + textNameIsNotUnique.length() + textEnding.length();

NewNameIsNotUnique::NewNameIsNotUnique(const FixedSizeString& tableName, const FixedSizeString& newTableName) noexcept
: MessageContainingTableName<ImmutableString>{tableName, ownTextLength + newTableName.length()},
newTableName{ImmutableString::fromString(newTableName)} { }

void NewNameIsNotUnique::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, tableName);
    TypesOutputer::output(outputStream, textBetweenNames);
    TypesOutputer::output(outputStream, newTableName);
    TypesOutputer::output(outputStream, textNameIsNotUnique);
    TypesOutputer::output(outputStream, newTableName);
    TypesOutputer::output(outputStream, textEnding);
}