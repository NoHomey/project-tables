#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"
#include "../../../Table/ColumnMetaData/ColumnMetaData.h"

class NewColumnAdded: public MessageContainingTableName<ImmutableString> {
public:
    NewColumnAdded(const FixedSizeString& tableName, ColumnMetaData::ColumnType columnType) noexcept;

    NewColumnAdded(const NewColumnAdded& other) = delete;

    NewColumnAdded(NewColumnAdded&& other) = delete;

    NewColumnAdded& operator=(const NewColumnAdded& other) = delete;

    NewColumnAdded& operator=(NewColumnAdded&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(ColumnMetaData::ColumnType columnType) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString columnTypeText;
};