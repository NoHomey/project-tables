#include "TableCreated.h"
#include "../../../TypesOutputer/TypesOutputer.h"

TableCreated TableCreated::instance;

ConstString TableCreated::textBeginning{"Query result: successfully created Table '"};

ConstString TableCreated::textEnding{"'."};

const size_t TableCreated::ownTextLength = textBeginning.length() + textEnding.length();

TableCreated* TableCreated::inject(const FixedSizeString& tableName) noexcept {
    instance.setTableName(tableName);
    instance.setTextLength(ownTextLength + tableName.length());
    return &instance;
}

void TableCreated::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}