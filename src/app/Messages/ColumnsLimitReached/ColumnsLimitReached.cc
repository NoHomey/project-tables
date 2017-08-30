#include "ColumnsLimitReached.h"
#include "../../../TypesOutputer/TypesOutputer.h"
#include "../../../Table/TableData/TableData.h"

ConstString ColumnsLimitReached::text{"Query Error: Could not add new Column. Columns count limit reached. The limit is: "};

ColumnsLimitReached ColumnsLimitReached::instance;

ColumnsLimitReached::ColumnsLimitReached() noexcept
: InfoModel{text.length() + TypesOutputer::outputCount(TableData::columnsLimit) + 1, false} { }

ColumnsLimitReached* ColumnsLimitReached::columnsLimitReached() {
    return &instance;
}

void ColumnsLimitReached::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    TypesOutputer::output(outputStream, TableData::columnsLimit);
    outputStream << '.';
}