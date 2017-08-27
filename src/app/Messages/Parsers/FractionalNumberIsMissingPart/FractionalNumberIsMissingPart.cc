#include "FractionalNumberIsMissingPart.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString FractionalNumberIsMissingPart::textBeginning{"Column type is 'FractionalNumber' but input value '"};

ConstString FractionalNumberIsMissingPart::textInvalidFractionalNumber{"' is invalid decimal fractional number. It has not "};

ConstString FractionalNumberIsMissingPart::textEnding{" part."};

const size_t FractionalNumberIsMissingPart::ownTextLength = textBeginning.length() +
                            textInvalidFractionalNumber.length() + textEnding.length();

FractionalNumberIsMissingPart::FractionalNumberIsMissingPart(ConstString& missingPart, TableTypes::Column column, ConstString& invalidToken)
: ParserMessage{column, ownTextLength + missingPart.length() + invalidToken.length()}, missingPart{missingPart},
invalidToken{FixedSizeString::fromString(invalidToken)} { }

void FractionalNumberIsMissingPart::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, invalidToken);
    TypesOutputer::output(outputStream, textInvalidFractionalNumber);
    TypesOutputer::output(outputStream, missingPart);
    TypesOutputer::output(outputStream, textEnding);
}