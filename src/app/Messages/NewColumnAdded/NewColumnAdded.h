#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"
#include "../../../Table/ColumnMetaData/ColumnMetaData.h"

class NewColumnAdded: public MessageContainingTableName<ImmutableString> {
public:
    static NewColumnAdded* inject(const FixedSizeString& tableName, ColumnMetaData::ColumnType columnType) noexcept;

public:
    void output(CharOutputStream& outputStream) const final;

    void releaseResources() noexcept final;

private:
    NewColumnAdded() noexcept = default;

    NewColumnAdded(const NewColumnAdded& other) = delete;

    NewColumnAdded(NewColumnAdded&& other) = delete;

    NewColumnAdded& operator=(const NewColumnAdded& other) = delete;

    NewColumnAdded& operator=(NewColumnAdded&& other) = delete;

private:
    void setColumnType(ColumnMetaData::ColumnType columnType) noexcept;

private:
    static NewColumnAdded instance;

    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ImmutableString columnTypeText;
};