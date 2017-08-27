#include "FractionalNumberDigitsLimit.h"
#include "../../../../TypesOutputer/TypesOutputer.h"
#include "../../../../Table/TableTypes/FractionalNumber.h"

ConstString FractionalNumberDigitsLimit::textBeginning{"'"};

ConstString FractionalNumberDigitsLimit::textEnding{"' is decimal fractional number which has more decimal digits than the allowed limit for the 'FractionalNumber' column type. The limit of decimal digits count is: "};

const size_t FractionalNumberDigitsLimit::ownTextLength = textBeginning.length() +
textEnding.length() + TypesOutputer::outputCount(FractionalNumber::MaxOfDigitsCount);

FractionalNumberDigitsLimit::FractionalNumberDigitsLimit(TableTypes::Column column, ConstString& invalidNumber)
: ParserMessage{column, ownTextLength + invalidNumber.length()},
invalidNumber{FixedSizeString::fromString(invalidNumber)} { }

void FractionalNumberDigitsLimit::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, invalidNumber);
    TypesOutputer::output(outputStream, textEnding);
    TypesOutputer::output(outputStream, FractionalNumber::MaxOfDigitsCount);
}