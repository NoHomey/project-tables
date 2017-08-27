#include "InvalidNumber.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString InvalidNumber::textBeginning{"Column type is '"};

ConstString InvalidNumber::textInputValue{"': and input value '"};

ConstString InvalidNumber::textInvalidNumber{"' is invalid "};

ConstString InvalidNumber::textInvalidSymbol{" number. Got invalid symbol: '"};

ConstString InvalidNumber::textAtPosition{"' at position: "};

ConstString InvalidNumber::textMakeSure{". Make sure valid "};

ConstString InvalidNumber::textEnding{" number is entered."};

const size_t InvalidNumber::ownTextLength = textBeginning.length() + textInputValue.length() + textInvalidNumber.length() +
textInvalidSymbol.length() + textAtPosition.length() + textMakeSure.length() + textEnding.length() + 1;

size_t InvalidNumber::calculateTextLength(ConstString& columnType, ConstString& numberType, const InvalidSymbolAtPosition& error) noexcept {
    return ownTextLength + columnType.length() + 2 * numberType.length() + error.getToken().length() +
                                                    TypesOutputer::outputCount(error.getPosition());
}

InvalidNumber::InvalidNumber(ConstString& columnType, ConstString& numberType, TableTypes::Column column, const InvalidSymbolAtPosition& error)
: ParserMessage{column, calculateTextLength(columnType, numberType, error)},
columnType{columnType}, numberType{numberType},
invalidToken{FixedSizeString::fromString(error.getToken())},
position{error.getPosition()}, invalidSymbol{error.getSymbol()} { }

void InvalidNumber::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, columnType);
    TypesOutputer::output(outputStream, textInputValue);
    TypesOutputer::output(outputStream, invalidToken);
    TypesOutputer::output(outputStream, textInvalidNumber);
    TypesOutputer::output(outputStream, numberType);
    TypesOutputer::output(outputStream, textInvalidSymbol);
    outputStream << invalidSymbol;
    TypesOutputer::output(outputStream, textAtPosition);
    TypesOutputer::output(outputStream, position);
    TypesOutputer::output(outputStream, textMakeSure);
    TypesOutputer::output(outputStream, numberType);
    TypesOutputer::output(outputStream, textEnding);
}