#include "TableHasNoNothingToBePrinted.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString TableHasNoNothingToBePrinted::textBeginning{"Warning Table '"};

ConstString TableHasNoNothingToBePrinted::textHasNo{"' has no "};

ConstString TableHasNoNothingToBePrinted::textEnding{". There is nothing to be printed."};

const size_t TableHasNoNothingToBePrinted::ownTextLength = textBeginning.length() + textHasNo.length() + textEnding.length();

TableHasNoNothingToBePrinted::TableHasNoNothingToBePrinted(const FixedSizeString& tableName, ConstString& tableHasNo) noexcept
: MessageContainingTableName<ImmutableString>{tableName, ownTextLength + tableHasNo.length()}, tableHasNo{tableHasNo} { }

void TableHasNoNothingToBePrinted::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textHasNo);
    TypesOutputer::output(outputStream, tableHasNo);
    TypesOutputer::output(outputStream, textEnding);
}