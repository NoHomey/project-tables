#include "WrongNumberOfColumns.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString WrongNumberOfColumns::textBeginning{"Insertation Error: Table '"};

ConstString WrongNumberOfColumns::textHas{"' has "};

ConstString WrongNumberOfColumns::textColumnsValues{" columns but recived values for "};

ConstString WrongNumberOfColumns::textEnding{" columns."};

const size_t WrongNumberOfColumns::ownTextLength = textBeginning.length() + 
        textHas.length() + textColumnsValues.length() + textEnding.length();

size_t WrongNumberOfColumns::calculateTextLength(const Table* table, TableTypes::Column valuesCount) noexcept {
    return ownTextLength + table->getName().length() + TypesOutputer::outputCount(valuesCount) +
                                            TypesOutputer::outputCount(table->columnsCount());
}

WrongNumberOfColumns::WrongNumberOfColumns(const Table* table, TableTypes::Column valuesCount)
: InfoModel{calculateTextLength(table, valuesCount), true}, tableName{ConstString::fromString(table->getName())},
valuesCount{valuesCount}, columnsCount{table->columnsCount()} { }

void WrongNumberOfColumns::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, tableName);
    TypesOutputer::output(outputStream, textHas);
    TypesOutputer::output(outputStream, columnsCount);
    TypesOutputer::output(outputStream, textColumnsValues);
    TypesOutputer::output(outputStream, valuesCount);
    TypesOutputer::output(outputStream, textEnding);
}