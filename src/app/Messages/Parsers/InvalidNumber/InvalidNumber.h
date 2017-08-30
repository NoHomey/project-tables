#pragma once

#include "../ParserMessage/ParserMessage.h"
#include "../../../../Parsers/Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"

class InvalidNumber: public ParserMessage {
public:
    InvalidNumber(ConstString& columnType, ConstString& numberType, TableTypes::Column column, const InvalidSymbolAtPosition& error);

    virtual ~InvalidNumber() noexcept = default;

    InvalidNumber(const InvalidNumber& other) = delete;

    InvalidNumber(InvalidNumber&& other) = delete;

    InvalidNumber& operator=(const InvalidNumber& other) = delete;

    InvalidNumber& operator=(InvalidNumber&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(ConstString& columnType, ConstString& numberType, const InvalidSymbolAtPosition& error) noexcept;

private:
    static ConstString textBeginning;
    
    static ConstString textInputValue;

    static ConstString textInvalidNumber;

    static ConstString textInvalidSymbol;
    
    static ConstString textAtPosition;

    static ConstString textMakeSure;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString columnType;

    ConstString numberType;

    FixedSizeString invalidToken;

    size_t position;

    char invalidSymbol;
};