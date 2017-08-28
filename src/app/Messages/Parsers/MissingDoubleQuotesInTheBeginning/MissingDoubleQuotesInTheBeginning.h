#pragma once

#include "../MissingDoubleQuotesInString/MissingDoubleQuotesInString.h"

class MissingDoubleQuotesInTheBeginning: public MissingDoubleQuotesInString {
public:
    MissingDoubleQuotesInTheBeginning(TableTypes::Column column, ConstString& invalidString);

    MissingDoubleQuotesInTheBeginning(const MissingDoubleQuotesInTheBeginning& other) = delete;

    MissingDoubleQuotesInTheBeginning(MissingDoubleQuotesInTheBeginning&& other) = delete;

    MissingDoubleQuotesInTheBeginning& operator=(const MissingDoubleQuotesInTheBeginning& other) = delete;

    MissingDoubleQuotesInTheBeginning& operator=(MissingDoubleQuotesInTheBeginning&& other) = delete;

private:
    static ConstString textMissingPosition;
};