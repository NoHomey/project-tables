#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableSaved: public MessageContainingTableName<ImmutableString> {
public:
    TableSaved(const FixedSizeString& tableName, ConstString& fileName);

    TableSaved(const TableSaved& other) = delete;

    TableSaved(TableSaved&& other) = delete;

    TableSaved& operator=(const TableSaved& other) = delete;

    TableSaved& operator=(TableSaved&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textAfterTableName;

    static const size_t ownTextLength;

private:
    FixedSizeString fileName;
};