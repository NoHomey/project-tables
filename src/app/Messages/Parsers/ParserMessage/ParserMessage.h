#pragma once

#include "../../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../../String/ConstString/ConstString.h"
#include "../../../../String/FixedSizeString/FixedSizeString.h"
#include "../../../../Table/TableTypes/TableTypes.h"

class ParserMessage: public InfoModel {
protected:
    ParserMessage(TableTypes::Column column, size_t textLength);

    virtual ~ParserMessage() noexcept = default;

    ParserMessage(const ParserMessage& other) = delete;

    ParserMessage(ParserMessage&& other) = delete;

    ParserMessage& operator=(const ParserMessage& other) = delete;

    ParserMessage& operator=(ParserMessage&& other) = delete;

protected:
    void output(CharOutputStream& outputStream) const final;

    virtual void outputOwnText(CharOutputStream& outputStream) const = 0;

protected:
    TableTypes::Column column;

private:
    static ConstString textBeginning;

    static ConstString textBetween;

    static const size_t parserTextLength; 
};