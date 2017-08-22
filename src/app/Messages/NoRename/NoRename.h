#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class NoRename: public MessageContainingTableName<ImmutableString> {
public:
    NoRename(const FixedSizeString& tableName) noexcept;

    NoRename(const NoRename& other) = delete;

    NoRename(NoRename&& other) = delete;

    NoRename& operator=(const NoRename& other) = delete;

    NoRename& operator=(NoRename&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;
    
private:

    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textEnding;

    static const size_t ownTextLength;
};