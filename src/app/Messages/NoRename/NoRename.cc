#include "NoRename.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../TypesOutputer/TypesOutputer.h"

NoRename NoRename::instance;

ConstString NoRename::textBeginning{"Query Warning: trying to rename Table '"};

ConstString NoRename::textBetweenNames{"' to '"};

ConstString NoRename::textEnding{"'. Resulted in no Table renaming. The two names are the same."};

const size_t NoRename::ownTextLength = textBeginning.length() + textBetweenNames.length() + textEnding.length();

NoRename* NoRename::inject(const FixedSizeString& tableName) noexcept {
    instance.tableName = {tableName.cString(), tableName.length()};
    return &instance;
}

size_t NoRename::textLength() const noexcept {
    return ownTextLength + 2 * tableName.length();
}

void NoRename::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, tableName);
    TypesOutputer::output(outputStream, textBetweenNames);
    TypesOutputer::output(outputStream, tableName);
    TypesOutputer::output(outputStream, textEnding);
}

void NoRename::releaseResources() noexcept {
    tableName = {};
}