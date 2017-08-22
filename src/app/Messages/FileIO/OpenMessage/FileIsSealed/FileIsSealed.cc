#include "FileIsSealed.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

FileIsSealed FileIsSealed::instance;

ConstString FileIsSealed::textBeginning{"Open Error: file: "};

ConstString FileIsSealed::textEnding{" is sealed."};

const size_t FileIsSealed::ownTextLength = textBeginning.length() + textEnding.length();

FileIsSealed* FileIsSealed::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(ownTextLength + fileName.length());
    return &instance;
}

void FileIsSealed::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}