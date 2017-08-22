#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableRenamed: public MessageContainingTableName<ImmutableString> {
public:
    static TableRenamed* inject(FixedSizeString&& oldTableName, const FixedSizeString& newTableName) noexcept;

public:
    void output(CharOutputStream& outputStream) const final;

    void releaseResources() noexcept final;

private:
    TableRenamed() noexcept = default;

    TableRenamed(const TableRenamed& other) = delete;

    TableRenamed(TableRenamed&& other) = delete;

    TableRenamed& operator=(const TableRenamed& other) = delete;

    TableRenamed& operator=(TableRenamed&& other) = delete;

private:
    static TableRenamed instance;

    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString oldName;
};