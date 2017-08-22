#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class InvalidTableName: public MessageContainingTableName<FixedSizeString> {
public:
    InvalidTableName(const String& tableName);

    InvalidTableName(const InvalidTableName& other) = delete;

    InvalidTableName(InvalidTableName&& other) = delete;

    InvalidTableName& operator=(const InvalidTableName& other) = delete;

    InvalidTableName& operator=(InvalidTableName&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;
};