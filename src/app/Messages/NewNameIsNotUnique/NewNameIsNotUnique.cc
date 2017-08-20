#include "NewNameIsNotUnique.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../TypesOutputer/TypesOutputer.h"

NewNameIsNotUnique NewNameIsNotUnique::instance;

ConstString NewNameIsNotUnique::textBeginning{"Query Error: trying to rename Table '"};

ConstString NewNameIsNotUnique::textBetweenNames{"' to '"};

ConstString NewNameIsNotUnique::textNameIsNotUnique{"'. The new name is not unique. Table with name '"};

ConstString NewNameIsNotUnique::textEnding{"' already exists."};

const size_t NewNameIsNotUnique::ownTextLength = textBeginning.length()
    + textBetweenNames.length() + textNameIsNotUnique.length() + textEnding.length();

NewNameIsNotUnique* NewNameIsNotUnique::inject(const FixedSizeString& tableName, const FixedSizeString& newTableName) noexcept {
    instance.tableName = {tableName.cString(), tableName.length()};
    instance.newName = {newTableName.cString(), newTableName.length()};
    return &instance;
}

size_t NewNameIsNotUnique::textLength() const noexcept {
    return ownTextLength + tableName.length() + 2 * newName.length();
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
    tableName = {};
    newName = {};
}