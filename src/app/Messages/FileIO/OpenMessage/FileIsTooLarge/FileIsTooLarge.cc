#include "FileIsTooLarge.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

FileIsTooLarge FileIsTooLarge::instance;

ConstString FileIsTooLarge::textBeginning{"Open Error: file: "};

ConstString FileIsTooLarge::textEnding{" is too large."};

const size_t FileIsTooLarge::ownTextLength = textBeginning.length() + textEnding.length();

FileIsTooLarge* FileIsTooLarge::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(ownTextLength + fileName.length());
    return &instance;
}

void FileIsTooLarge::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}