#include "TableHasLessColumns.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString TableHasLessColumns::textBeginning{"Query Error: Table '"};

ConstString TableHasLessColumns::textHas{"' has "};

ConstString TableHasLessColumns::textEnding{" columns which is less than "};

const size_t TableHasLessColumns::ownTextLength = textBeginning.length() + textHas.length() + textEnding.length();

size_t TableHasLessColumns::calculateTextLength(const Table& table, TableTypes::Column column) noexcept {
    return ownTextLength + TypesOutputer::outputCount(column) + TypesOutputer::outputCount(table.columnsCount());
}

TableHasLessColumns::TableHasLessColumns(const Table& table, TableTypes::Column column)
: MessageContainingTableName<ImmutableString>{table.getName(), calculateTextLength(table, column)},
column{column}, columnsCount{table.columnsCount()} { }

void TableHasLessColumns::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textHas);
    TypesOutputer::output(outputStream, columnsCount);
    TypesOutputer::output(outputStream, textEnding);
    TypesOutputer::output(outputStream, column);
}