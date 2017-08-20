#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class InvalidTableName: public MessageContainingTableName {
public:
    static InvalidTableName* inject(const String& tableName);

public:
    size_t textLength() const noexcept final;

    void output(CharOutputStream& outputStream) const final;

private:
    InvalidTableName() noexcept = default;

    InvalidTableName(const InvalidTableName& other) = delete;

    InvalidTableName(InvalidTableName&& other) = delete;

    InvalidTableName& operator=(const InvalidTableName& other) = delete;

    InvalidTableName& operator=(InvalidTableName&& other) = delete;

private:
    static InvalidTableName instance;

    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;
};