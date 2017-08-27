#include "ParserMessage.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString ParserMessage::textBeginning{"Parser Error: Error in value for column "};

ConstString ParserMessage::textBetween{": "};

const size_t ParserMessage::parserTextLength = textBeginning.length() + textBetween.length();

ParserMessage::ParserMessage(TableTypes::Column column, size_t textLength)
: InfoModel{parserTextLength + textLength + TypesOutputer::outputCount(column + 1), true}, column{column + 1} { }

void ParserMessage::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, column);
    TypesOutputer::output(outputStream, textBetween);
    outputOwnText(outputStream);
}