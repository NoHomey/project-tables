#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class NoRowsSelected: public MessageContainingTableName<ImmutableString> {
public:
    NoRowsSelected(const FixedSizeString& tableName) noexcept;

    virtual ~NoRowsSelected() noexcept = default;

    NoRowsSelected(const NoRowsSelected& other) = delete;

    NoRowsSelected(NoRowsSelected&& other) = delete;

    NoRowsSelected& operator=(const NoRowsSelected& other) = delete;

    NoRowsSelected& operator=(NoRowsSelected&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;
};