#include "InvalidTableName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString InvalidTableName::textBeginning{"Parse Error: '"};

ConstString InvalidTableName::textInvalidTableName{"' is invalid table name identificator. Got invalid symbol: '"};

ConstString InvalidTableName::textAtPosition{"' at position: "};

ConstString InvalidTableName::textEnding{". Valid table name identificator begins with a letter and can have: letter, digit, '_', '#' or '$' for any subsequent symbol."};

const size_t InvalidTableName::ownTextLength = textBeginning.length() + textInvalidTableName.length() +
                                                    textAtPosition.length() + textEnding.length() + 1;

size_t InvalidTableName::calculateTextLength(const InvalidSymbolAtPosition& error) noexcept {
    return ownTextLength + TypesOutputer::outputCount(error.getPosition());
}

InvalidTableName::InvalidTableName(const InvalidSymbolAtPosition& error)
: MessageContainingTableName<FixedSizeString>{error.getToken(), calculateTextLength(error)},
position{error.getPosition()}, invalidSymbol{error.getSymbol()} { }

void InvalidTableName::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textInvalidTableName);
    outputStream << invalidSymbol;
    TypesOutputer::output(outputStream, textAtPosition);
    TypesOutputer::output(outputStream, position);
    TypesOutputer::output(outputStream, textEnding);
}