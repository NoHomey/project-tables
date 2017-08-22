#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableRenamed: public MessageContainingTableName<ImmutableString> {
public:
    TableRenamed(FixedSizeString&& oldTableName, const FixedSizeString& newTableName);

    TableRenamed(const TableRenamed& other) = delete;

    TableRenamed(TableRenamed&& other) = delete;

    TableRenamed& operator=(const TableRenamed& other) = delete;

    TableRenamed& operator=(TableRenamed&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString oldName;
};