#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableExists: public MessageContainingTableName<ImmutableString> {
public:
    static TableExists* inject(const FixedSizeString& tableName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    TableExists() noexcept = default;

    TableExists(const TableExists& other) = delete;

    TableExists(TableExists&& other) = delete;

    TableExists& operator=(const TableExists& other) = delete;

    TableExists& operator=(TableExists&& other) = delete;

private:
    static TableExists instance;

    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;
};