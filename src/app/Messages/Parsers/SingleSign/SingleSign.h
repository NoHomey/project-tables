#pragma once

#include "../ParserMessage/ParserMessage.h"

class SingleSign: public ParserMessage {
public:
    SingleSign(TableTypes::Column column, char signSymbol);

    SingleSign(const SingleSign& other) = delete;

    SingleSign(SingleSign&& other) = delete;

    SingleSign& operator=(const SingleSign& other) = delete;

    SingleSign& operator=(SingleSign&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    char signSymbol;
};