#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"
#include "../../../Parsers/Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"

class InvalidTableName: public MessageContainingTableName<FixedSizeString> {
public:
    InvalidTableName(const InvalidSymbolAtPosition& error);

    InvalidTableName(const InvalidTableName& other) = delete;

    InvalidTableName(InvalidTableName&& other) = delete;

    InvalidTableName& operator=(const InvalidTableName& other) = delete;

    InvalidTableName& operator=(InvalidTableName&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(const InvalidSymbolAtPosition& error) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textInvalidTableName;
    
    static ConstString textAtPosition;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    size_t position;

    char invalidSymbol;
};