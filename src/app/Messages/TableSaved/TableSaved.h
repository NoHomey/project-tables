#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableSaved: public MessageContainingTableName<ImmutableString> {
public:
    static TableSaved* inject(const FixedSizeString& tableName, ConstString& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

    void releaseResources() noexcept final;

private:
    TableSaved() noexcept = default;

    TableSaved(const TableSaved& other) = delete;

    TableSaved(TableSaved&& other) = delete;

    TableSaved& operator=(const TableSaved& other) = delete;

    TableSaved& operator=(TableSaved&& other) = delete;

private:
    static TableSaved instance;

    static ConstString textBeginning;

    static ConstString textAfterTableName;

    static const size_t ownTextLength;

private:
    FixedSizeString fileName;
};