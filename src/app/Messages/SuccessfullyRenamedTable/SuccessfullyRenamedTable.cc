#include "SuccessfullyRenamedTable.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../TypesOutputer/TypesOutputer.h"

SuccessfullyRenamedTable SuccessfullyRenamedTable::instance;

ConstString SuccessfullyRenamedTable::textBeginning{"Query result: successfully renamed Table '"};

ConstString SuccessfullyRenamedTable::textBetweenNames{"' to '"};

ConstString SuccessfullyRenamedTable::textEnding{"'."};

const size_t SuccessfullyRenamedTable::ownTextLength = textBeginning.length() + textBetweenNames.length() + textEnding.length();

SuccessfullyRenamedTable* SuccessfullyRenamedTable::inject(FixedSizeString&& oldTableName, const FixedSizeString& newTableName) noexcept {
    instance.oldName = std::move(oldTableName);
    instance.newName = {newTableName.cString(), newTableName.length()};
    return &instance;
}

size_t SuccessfullyRenamedTable::textLength() const noexcept {
    return ownTextLength + oldName.length() + newName.length();
}

void SuccessfullyRenamedTable::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, oldName);
    TypesOutputer::output(outputStream, textBetweenNames);
    TypesOutputer::output(outputStream, newName);
    TypesOutputer::output(outputStream, textEnding);
}

void SuccessfullyRenamedTable::releaseResources() noexcept {
    oldName = {};
    newName = {};
}