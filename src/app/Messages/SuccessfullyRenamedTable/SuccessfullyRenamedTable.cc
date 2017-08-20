#include "SuccessfullyRenamedTable.h"
#include "../../../TypesOutputer/TypesOutputer.h"

SuccessfullyRenamedTable SuccessfullyRenamedTable::instance;

ConstString SuccessfullyRenamedTable::textBeginning{"Query result: successfully renamed Table '"};

ConstString SuccessfullyRenamedTable::textBetweenNames{"' to '"};

ConstString SuccessfullyRenamedTable::textEnding{"'."};

const size_t SuccessfullyRenamedTable::ownTextLength = textBeginning.length() + textBetweenNames.length() + textEnding.length();

SuccessfullyRenamedTable* SuccessfullyRenamedTable::inject(FixedSizeString&& oldTableName, const FixedSizeString& newTableName) noexcept {
    instance.oldName = std::move(oldTableName);
    instance.setTableName(newTableName);
    instance.setTextLength(ownTextLength + oldTableName.length() + newTableName.length());
    return &instance;
}

void SuccessfullyRenamedTable::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, oldName);
    TypesOutputer::output(outputStream, textBetweenNames);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}

void SuccessfullyRenamedTable::releaseResources() noexcept {
    MessageContainingTableName<ImmutableString>::releaseResources();
    oldName = {};
}