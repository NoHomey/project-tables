#include "NewColumnAdded.h"
#include "../../../TypesOutputer/TypesOutputer.h"

NewColumnAdded NewColumnAdded::instance;

ConstString NewColumnAdded::textBeginning{"Query result: successfully added new column with type '"};

ConstString NewColumnAdded::textBetweenNames{"' to Table '"};

ConstString NewColumnAdded::textEnding{"'."};

const size_t NewColumnAdded::ownTextLength = textBeginning.length() + textBetweenNames.length() + textEnding.length();

void NewColumnAdded::setColumnType(ColumnMetaData::ColumnType columnType) noexcept {
    columnTypeText = ColumnMetaData::columnTypeAsString(columnType);
}

NewColumnAdded* NewColumnAdded::inject(const FixedSizeString& tableName, ColumnMetaData::ColumnType columnType) noexcept {
    instance.setTableName(tableName);
    instance.setColumnType(columnType);
    instance.setTextLength(ownTextLength + tableName.length() + instance.columnTypeText.length());
    return &instance;
}

void NewColumnAdded::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, columnTypeText);
    TypesOutputer::output(outputStream, textBetweenNames);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}

void NewColumnAdded::releaseResources() noexcept {
    MessageContainingTableName<ImmutableString>::releaseResources();
    columnTypeText = {};
}