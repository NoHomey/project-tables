#include "NoRename.h"
#include "../../../TypesOutputer/TypesOutputer.h"

NoRename NoRename::instance;

ConstString NoRename::textBeginning{"Query Warning: trying to rename Table '"};

ConstString NoRename::textBetweenNames{"' to '"};

ConstString NoRename::textEnding{"'. Resulted in no Table renaming. The two names are the same."};

const size_t NoRename::ownTextLength = textBeginning.length() + textBetweenNames.length() + textEnding.length();

NoRename* NoRename::inject(const FixedSizeString& tableName) noexcept {
    instance.setTableName(tableName);
    instance.setTextLength(ownTextLength + 2 * tableName.length());
    return &instance;
}

void NoRename::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textBetweenNames);
    outputTableName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}