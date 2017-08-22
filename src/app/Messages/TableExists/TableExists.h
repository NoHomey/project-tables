#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableExists: public MessageContainingTableName<ImmutableString> {
public:
    TableExists(const FixedSizeString& tableName) noexcept;

    TableExists(const TableExists& other) = delete;

    TableExists(TableExists&& other) = delete;

    TableExists& operator=(const TableExists& other) = delete;

    TableExists& operator=(TableExists&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;
};