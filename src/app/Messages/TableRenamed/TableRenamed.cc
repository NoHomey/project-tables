#include "TableRenamed.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString TableRenamed::textBeginning{"Query result: successfully renamed Table '"};

ConstString TableRenamed::textBetweenNames{"' to '"};

ConstString TableRenamed::textEnding{"'."};

const size_t TableRenamed::ownTextLength = textBeginning.length() + textBetweenNames.length() + textEnding.length();

TableRenamed::TableRenamed(FixedSizeString&& oldTableName, const FixedSizeString& newTableName)
: MessageContainingTableName<ImmutableString>{newTableName, ownTextLength + oldTableName.length()},
oldName{std::move(oldTableName)} { }

void TableRenamed::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, oldName);
    TypesOutputer::output(outputStream, textBetweenNames);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}