#include "ColumnNumberOutOfRange.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"
#include "../../../../../Parsers/ColumnNumberParser/ColumnNumberParser.h"

ConstString ColumnNumberOutOfRange::textBeginning{"Parser Error: '"};

ConstString ColumnNumberOutOfRange::textColumnNumberOutOfRange{"' is Column number out of the range of possible numbers for Column numbers. Valid value for Column number is natural number in the range ["};

ConstString ColumnNumberOutOfRange::textBetweenLimits{", "};

ConstString ColumnNumberOutOfRange::textEnding{"]."};

const size_t ColumnNumberOutOfRange::ownTextLength = textBeginning.length() + textColumnNumberOutOfRange.length() +
        TypesOutputer::outputCount(ColumnNumberParser::Min) + TypesOutputer::outputCount(ColumnNumberParser::Max) +
                                                                textBetweenLimits.length() + textEnding.length();

ColumnNumberOutOfRange::ColumnNumberOutOfRange(ConstString& outOfRangeColumnNumber)
: InfoModel{ownTextLength + outOfRangeColumnNumber.length(), true},
outOfRangeColumnNumber{FixedSizeString::fromString(outOfRangeColumnNumber)} { }

void ColumnNumberOutOfRange::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, outOfRangeColumnNumber);
    TypesOutputer::output(outputStream, textColumnNumberOutOfRange);
    TypesOutputer::output(outputStream, ColumnNumberParser::Min);
    TypesOutputer::output(outputStream, textBetweenLimits);
    TypesOutputer::output(outputStream, ColumnNumberParser::Max);
    TypesOutputer::output(outputStream, textEnding);
}