#include "TableExists.h"
#include "../../../TypesOutputer/TypesOutputer.h"

TableExists TableExists::instance;

ConstString TableExists::textBeginning{"Query Error: Table with name '"};

ConstString TableExists::textEnding{"' already exists. Either Rename it ot choose different name."};

const size_t TableExists::ownTextLength = textBeginning.length() + textEnding.length();

TableExists* TableExists::inject(const FixedSizeString& tableName) {
    instance.setTableName(tableName);
    instance.setTextLength(ownTextLength + tableName.length());
    return &instance;
}

void TableExists::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}