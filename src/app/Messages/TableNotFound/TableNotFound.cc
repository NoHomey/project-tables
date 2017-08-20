#include "TableNotFound.h"
#include "../../../TypesOutputer/TypesOutputer.h"

TableNotFound TableNotFound::instance;

ConstString TableNotFound::textBeginning{"Query Error: Cannot find table with name : '"};

ConstString TableNotFound::textEnsureExists{"'. Ensure table with name: '"};

ConstString TableNotFound::textEnding{"' is loaded or created. For list of all existing tables type: Showtables."};

const size_t TableNotFound::ownTextLength = textBeginning.length() + textEnsureExists.length() + textEnding.length();

TableNotFound* TableNotFound::inject(const String& tableName) {
    instance.setTableName(tableName);
    return &instance;
}

size_t TableNotFound::textLength() const noexcept {
    return ownTextLength + tableName.length();
}

void TableNotFound::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnsureExists);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}