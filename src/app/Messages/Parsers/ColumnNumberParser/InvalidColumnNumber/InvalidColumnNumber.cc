#include "InvalidColumnNumber.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString InvalidColumnNumber::textBeginning{"Parser Error: invalid Column number: '"};

ConstString InvalidColumnNumber::textInvalidSymbol{"' . Got invalid symbol: '"};

ConstString InvalidColumnNumber::textAtPosition{"' at position: "};

ConstString InvalidColumnNumber::textEnding{". Make sure valid Column number is entered."};

const size_t InvalidColumnNumber::ownTextLength = textBeginning.length() +
textInvalidSymbol.length() + textAtPosition.length() + textEnding.length() + 1;

size_t InvalidColumnNumber::calculateTextLength(const ColumnNumberParser::InvalidColumnNumber& error) noexcept {
    return ownTextLength  + error.getToken().length() + TypesOutputer::outputCount(error.getPosition());
}

InvalidColumnNumber::InvalidColumnNumber(const ColumnNumberParser::InvalidColumnNumber& error)
: InfoModel{calculateTextLength(error), true},
invalidToken{FixedSizeString::fromString(error.getToken())},
position{error.getPosition()}, invalidSymbol{error.getSymbol()} { }

void InvalidColumnNumber::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, invalidToken);
    TypesOutputer::output(outputStream, textInvalidSymbol);
    outputStream << invalidSymbol;
    TypesOutputer::output(outputStream, textAtPosition);
    TypesOutputer::output(outputStream, position);
    TypesOutputer::output(outputStream, textEnding);
}