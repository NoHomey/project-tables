#include "RowsQueryResult.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString RowsQueryResult::textBeginning{"Query Result: "};

ConstString RowsQueryResult::textEnding{" rows were "};

const size_t RowsQueryResult::ownTextLength = textBeginning.length() + textEnding.length();

size_t RowsQueryResult::calculateTextLegth(ConstString& action, TableTypes::Row rowsCounted) noexcept {
    return ownTextLength + TypesOutputer::outputCount(rowsCounted) + action.length() + 1;
}

RowsQueryResult::RowsQueryResult(ConstString& action, TableTypes::Row rowsCounted) noexcept
: InfoModel{calculateTextLegth(action, rowsCounted), true},
action{action}, rowsCounted{rowsCounted} { }

void RowsQueryResult::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, rowsCounted);
    TypesOutputer::output(outputStream, textEnding);
    TypesOutputer::output(outputStream, action);
    outputStream << '.';
}