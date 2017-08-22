#include "TableRenamed.h"
#include "../../../TypesOutputer/TypesOutputer.h"

TableRenamed TableRenamed::instance;

ConstString TableRenamed::textBeginning{"Query result: successfully renamed Table '"};

ConstString TableRenamed::textBetweenNames{"' to '"};

ConstString TableRenamed::textEnding{"'."};

const size_t TableRenamed::ownTextLength = textBeginning.length() + textBetweenNames.length() + textEnding.length();

TableRenamed* TableRenamed::inject(FixedSizeString&& oldTableName, const FixedSizeString& newTableName) noexcept {
    instance.oldName = std::move(oldTableName);
    instance.setTableName(newTableName);
    instance.setTextLength(ownTextLength + oldTableName.length() + newTableName.length());
    return &instance;
}

void TableRenamed::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, oldName);
    TypesOutputer::output(outputStream, textBetweenNames);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}

void TableRenamed::releaseResources() noexcept {
    MessageContainingTableName<ImmutableString>::releaseResources();
    oldName = {};
}