#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableCreated: public MessageContainingTableName<ImmutableString> {
public:
    TableCreated(const FixedSizeString& tableName) noexcept;

    TableCreated(const TableCreated& other) = delete;

    TableCreated(TableCreated&& other) = delete;

    TableCreated& operator=(const TableCreated& other) = delete;

    TableCreated& operator=(TableCreated&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;
};