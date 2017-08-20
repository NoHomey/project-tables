#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableCreated: public MessageContainingTableName<ImmutableString> {
public:
    static TableCreated* inject(const FixedSizeString& tableName) noexcept;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    TableCreated() noexcept = default;

    TableCreated(const TableCreated& other) = delete;

    TableCreated(TableCreated&& other) = delete;

    TableCreated& operator=(const TableCreated& other) = delete;

    TableCreated& operator=(TableCreated&& other) = delete;

private:
    static TableCreated instance;

    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;
};