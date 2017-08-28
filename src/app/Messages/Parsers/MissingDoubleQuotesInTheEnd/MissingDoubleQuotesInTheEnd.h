#pragma once

#include "../MissingDoubleQuotesInString/MissingDoubleQuotesInString.h"

class MissingDoubleQuotesInTheEnd: public MissingDoubleQuotesInString {
public:
    MissingDoubleQuotesInTheEnd(TableTypes::Column column, ConstString& invalidString);

    MissingDoubleQuotesInTheEnd(const MissingDoubleQuotesInTheEnd& other) = delete;

    MissingDoubleQuotesInTheEnd(MissingDoubleQuotesInTheEnd&& other) = delete;

    MissingDoubleQuotesInTheEnd& operator=(const MissingDoubleQuotesInTheEnd& other) = delete;

    MissingDoubleQuotesInTheEnd& operator=(MissingDoubleQuotesInTheEnd&& other) = delete;

private:
    static ConstString textMissingPosition;
};