#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableNotFound: public MessageContainingTableName<FixedSizeString> {
public:
    TableNotFound(const String& tableName);

    TableNotFound(const TableNotFound& other) = delete;

    TableNotFound(TableNotFound&& other) = delete;

    TableNotFound& operator=(const TableNotFound& other) = delete;

    TableNotFound& operator=(TableNotFound&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnsureExists;

    static ConstString textEnding;

    static const size_t ownTextLength;
};