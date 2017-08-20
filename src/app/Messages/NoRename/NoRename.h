#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class NoRename: public MessageContainingTableName<ImmutableString> {
public:
    static NoRename* inject(const FixedSizeString& tableName) noexcept;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    NoRename() noexcept = default;

    NoRename(const NoRename& other) = delete;

    NoRename(NoRename&& other) = delete;

    NoRename& operator=(const NoRename& other) = delete;

    NoRename& operator=(NoRename&& other) = delete;

private:
    static NoRename instance;

    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textEnding;

    static const size_t ownTextLength;
};