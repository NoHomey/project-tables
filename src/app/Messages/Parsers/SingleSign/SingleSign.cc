#include "SingleSign.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString SingleSign::textBeginning{"Column type is Integer but got single sign symbol: '"};

ConstString SingleSign::textEnding{"' make sure valid integer number is entered."};

const size_t SingleSign::ownTextLength = textBeginning.length() + textEnding.length() + 1;

SingleSign::SingleSign(TableTypes::Column column, char signSymbol)
: ParserMessage{column, ownTextLength}, signSymbol{signSymbol}  { }

void SingleSign::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputStream << signSymbol;
    TypesOutputer::output(outputStream, textEnding);
}