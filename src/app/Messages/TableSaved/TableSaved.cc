#include "TableSaved.h"
#include "../../../TypesOutputer/TypesOutputer.h"

TableSaved TableSaved::instance;

ConstString TableSaved::textBeginning{"Query result: successfully saved Table '"};

ConstString TableSaved::textAfterTableName{"' to file: "};

const size_t TableSaved::ownTextLength = textAfterTableName.length();

TableSaved* TableSaved::inject(const FixedSizeString& tableName, ConstString& fileName) {
    instance.setTableName(tableName);
    instance.fileName = FixedSizeString::fromString(fileName);
    instance.setTextLength(ownTextLength + tableName.length() + fileName.length());
    return &instance;
}

void TableSaved::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textAfterTableName);
    TypesOutputer::output(outputStream, fileName);
}

void TableSaved::releaseResources() noexcept {
    MessageContainingTableName<ImmutableString>::releaseResources();
    fileName = {};
}