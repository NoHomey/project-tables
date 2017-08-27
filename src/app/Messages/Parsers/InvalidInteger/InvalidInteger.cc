#include "InvalidInteger.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString InvalidInteger::textBeginning{"Column type is Integer and input value '"};

ConstString InvalidInteger::textInvalidInteger{"' is invalid integer number. Got invalid symbol: '"};

ConstString InvalidInteger::textAtPosition{"' at position: "};

ConstString InvalidInteger::textEnding{". Make sure valid integer number is entered."};

const size_t InvalidInteger::ownTextLength = textBeginning.length() + textInvalidInteger.length() +
                                                    textAtPosition.length() + textEnding.length() + 1;

size_t InvalidInteger::calculateTextLength(const IntegerParser::InvalidInteger& error) noexcept {
    return ownTextLength + error.getToken().length() + TypesOutputer::outputCount(error.getPosition());
}

InvalidInteger::InvalidInteger(TableTypes::Column column, const IntegerParser::InvalidInteger& error)
: ParserMessage{column, calculateTextLength(error)}, invalidToken{FixedSizeString::fromString(error.getToken())},
position{error.getPosition()}, invalidSymbol{error.getSymbol()} { }

void InvalidInteger::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, invalidToken);
    TypesOutputer::output(outputStream, textInvalidInteger);
    outputStream << invalidSymbol;
    TypesOutputer::output(outputStream, textAtPosition);
    TypesOutputer::output(outputStream, position);
    TypesOutputer::output(outputStream, textEnding);
}