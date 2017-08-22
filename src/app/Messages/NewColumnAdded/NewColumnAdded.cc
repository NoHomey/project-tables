#include "NewColumnAdded.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString NewColumnAdded::textBeginning{"Query result: successfully added new column with type '"};

ConstString NewColumnAdded::textBetweenNames{"' to Table '"};

ConstString NewColumnAdded::textEnding{"'."};

const size_t NewColumnAdded::ownTextLength = textBeginning.length() + textBetweenNames.length() + textEnding.length();

size_t NewColumnAdded::calculateTextLength(ColumnMetaData::ColumnType columnType) noexcept {
    return ownTextLength + ColumnMetaData::columnTypeAsString(columnType).length();
}

NewColumnAdded::NewColumnAdded(const FixedSizeString& tableName, ColumnMetaData::ColumnType columnType) noexcept
: MessageContainingTableName<ImmutableString>{tableName, calculateTextLength(columnType)},
columnTypeText{ColumnMetaData::columnTypeAsString(columnType)} { }

void NewColumnAdded::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, columnTypeText);
    TypesOutputer::output(outputStream, textBetweenNames);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}