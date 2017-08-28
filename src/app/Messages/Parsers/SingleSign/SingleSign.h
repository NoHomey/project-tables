#pragma once

#include "../ParserMessage/ParserMessage.h"
#include "../../../../Table/ColumnMetaData/ColumnMetaData.h"

class SingleSign: public ParserMessage {
public:
    SingleSign(TableTypes::Column column, ColumnMetaData::ColumnType columnType, char signSymbol);

    SingleSign(const SingleSign& other) = delete;

    SingleSign(SingleSign&& other) = delete;

    SingleSign& operator=(const SingleSign& other) = delete;

    SingleSign& operator=(SingleSign&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textSingleSign;

    static ConstString textMakeSure;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString columnType;

    char signSymbol;
};