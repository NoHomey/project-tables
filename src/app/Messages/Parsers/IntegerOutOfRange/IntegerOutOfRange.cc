#include "IntegerOutOfRange.h"
#include "../../../../TypesOutputer/TypesOutputer.h"
#include "../../../../Table/TableTypes/StringifiedIntegerLimits.h"

ConstString IntegerOutOfRange::textBeginning{"'"};

ConstString IntegerOutOfRange::textIntegerOutOfRange{"' is integer number out of the range of possible integer numbers for the 'Integer' column type. Valid value for column of type 'Integer' is integer number in the range ["};

ConstString IntegerOutOfRange::textBetweenLimits{", "};

ConstString IntegerOutOfRange::textEnding{"]."};

const size_t IntegerOutOfRange::ownTextLength = textBeginning.length() + textIntegerOutOfRange.length() +
                        StringifiedIntegerLimits::Min.length() + StringifiedIntegerLimits::Max.length() +
                                                        textBetweenLimits.length() + textEnding.length();

IntegerOutOfRange::IntegerOutOfRange(TableTypes::Column column, ConstString& outOfRangeInteger)
: ParserMessage{column, ownTextLength + outOfRangeInteger.length()},
outOfRangeInteger{FixedSizeString::fromString(outOfRangeInteger)} { }

void IntegerOutOfRange::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, outOfRangeInteger);
    TypesOutputer::output(outputStream, textIntegerOutOfRange);
    TypesOutputer::output(outputStream, StringifiedIntegerLimits::Min);
    TypesOutputer::output(outputStream, textBetweenLimits);
    TypesOutputer::output(outputStream, StringifiedIntegerLimits::Max);
    TypesOutputer::output(outputStream, textEnding);
}