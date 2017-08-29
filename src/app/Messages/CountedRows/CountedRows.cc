#include "CountedRows.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString CountedRows::textBeginning{"Query Result: "};

ConstString CountedRows::textEnding{" rows were counted."};

const size_t CountedRows::ownTextLength = textBeginning.length() + textEnding.length();

CountedRows::CountedRows(TableTypes::Row rowsCounted) noexcept
: InfoModel{ownTextLength + TypesOutputer::outputCount(rowsCounted), true}, rowsCounted{rowsCounted} { }


void CountedRows::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, rowsCounted);
    TypesOutputer::output(outputStream, textEnding);
}