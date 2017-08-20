#include "MessageContainingTableName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

void MessageContainingTableName::releaseResources() noexcept {
    tableName = {};
}

void MessageContainingTableName::setTableName(const String& name) {
    tableName = {name.cString(), name.length()};
}

void MessageContainingTableName::outputTableName(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, tableName);
}