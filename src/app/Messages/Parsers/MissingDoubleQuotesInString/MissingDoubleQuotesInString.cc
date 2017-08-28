#include "MissingDoubleQuotesInString.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString MissingDoubleQuotesInString::textBeginning{"Column type is 'String' but value: '"};

ConstString MissingDoubleQuotesInString::textMissingDoubleQuotes{"' is missing double quotes in the "};

ConstString MissingDoubleQuotesInString::textMakeSure{". Make sure to add '\"' in the "};

ConstString MissingDoubleQuotesInString::textEnding{" of the string."};

const size_t MissingDoubleQuotesInString::ownTextLength = textBeginning.length() +
    textMissingDoubleQuotes.length() + textMakeSure.length() + textEnding.length();

MissingDoubleQuotesInString::MissingDoubleQuotesInString(ConstString& missingPosition, TableTypes::Column column, ConstString& invalidString)
: ParserMessage{column, ownTextLength + invalidString.length() + 2 * missingPosition.length()},
invalidString{FixedSizeString::fromString(invalidString)}, missingPosition{missingPosition} { }

void MissingDoubleQuotesInString::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, invalidString);
    TypesOutputer::output(outputStream, textMissingDoubleQuotes);
    TypesOutputer::output(outputStream, missingPosition);
    TypesOutputer::output(outputStream, textMakeSure);
    TypesOutputer::output(outputStream, missingPosition);
    TypesOutputer::output(outputStream, textEnding);
}