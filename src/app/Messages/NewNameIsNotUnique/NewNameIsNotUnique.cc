#include "NewNameIsNotUnique.h"
#include "../../../TypesOutputer/TypesOutputer.h"

NewNameIsNotUnique NewNameIsNotUnique::instance;

ConstString NewNameIsNotUnique::textBeginning{"Query Error: trying to rename Table '"};

ConstString NewNameIsNotUnique::textBetweenNames{"' to '"};

ConstString NewNameIsNotUnique::textNameIsNotUnique{"'. The new name is not unique. Table with name '"};

ConstString NewNameIsNotUnique::textEnding{"' already exists."};

const size_t NewNameIsNotUnique::ownTextLength = textBeginning.length()
    + textBetweenNames.length() + textNameIsNotUnique.length() + textEnding.length();

NewNameIsNotUnique* NewNameIsNotUnique::inject(const FixedSizeString& tableName, const FixedSizeString& newTableName) noexcept {
    instance.setTableName(tableName);
    instance.newName = ImmutableString::fromString(newTableName);
    instance.setTextLength(ownTextLength + tableName.length() + 2 * newTableName.length());
    return &instance;
}

void NewNameIsNotUnique::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, tableName);
    TypesOutputer::output(outputStream, textBetweenNames);
    TypesOutputer::output(outputStream, newName);
    TypesOutputer::output(outputStream, textNameIsNotUnique);
    TypesOutputer::output(outputStream, newName);
    TypesOutputer::output(outputStream, textEnding);
}

void NewNameIsNotUnique::releaseResources() noexcept {
    MessageContainingTableName<ImmutableString>::releaseResources();
    newName = {};
}