#include "UnEscapedBackslashInString.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString UnEscapedBackslashInString::textBeginning{"Column type is 'String' and value: '"};

ConstString UnEscapedBackslashInString::textEnding{"' has backslash that is not escaping any symbol at position: "};

const size_t UnEscapedBackslashInString::ownTextLength = textBeginning.length() + textEnding.length();

size_t UnEscapedBackslashInString::calculateTextLength(const StringParser::UnEscapedBackslash& error) noexcept {
    return ownTextLength + error.getToken().length() + TypesOutputer::outputCount(error.getPosition());
}

UnEscapedBackslashInString::UnEscapedBackslashInString(TableTypes::Column column, const StringParser::UnEscapedBackslash& error)
: ParserMessage{column, calculateTextLength(error)}, position{error.getPosition()},
invalidToken{FixedSizeString::fromString(error.getToken())} { }

void UnEscapedBackslashInString::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, invalidToken);
    TypesOutputer::output(outputStream, textEnding);
    TypesOutputer::output(outputStream, position);
}