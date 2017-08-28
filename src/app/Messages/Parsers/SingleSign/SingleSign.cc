#include "SingleSign.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString SingleSign::textBeginning{"Column type is '"};

ConstString SingleSign::textSingleSign{"' but got single sign symbol: '"};

ConstString SingleSign::textMakeSure{"' make sure valid value for Column type '"};

ConstString SingleSign::textEnding{"' is entered."};

const size_t SingleSign::ownTextLength = textBeginning.length() +
textSingleSign.length() + textMakeSure.length() + textEnding.length() + 1;

SingleSign::SingleSign(TableTypes::Column column, ColumnMetaData::ColumnType columnType, char signSymbol)
: ParserMessage{column, ownTextLength + 2 * ColumnMetaData::columnTypeAsString(columnType).length()},
columnType{ColumnMetaData::columnTypeAsString(columnType)},
signSymbol{signSymbol}  { }

void SingleSign::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, columnType);
    TypesOutputer::output(outputStream, textSingleSign);
    outputStream << signSymbol;
    TypesOutputer::output(outputStream, textMakeSure);
    TypesOutputer::output(outputStream, columnType);
    TypesOutputer::output(outputStream, textEnding);
}