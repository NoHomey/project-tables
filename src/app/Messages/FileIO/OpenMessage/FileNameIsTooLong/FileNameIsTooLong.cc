#include "FileNameIsTooLong.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

FileNameIsTooLong FileNameIsTooLong::instance;

ConstString FileNameIsTooLong::textBeginning{"Open Error: file name: "};

ConstString FileNameIsTooLong::textEnding{" is too long."};

const size_t FileNameIsTooLong::ownTextLength = textBeginning.length() + textEnding.length();

FileNameIsTooLong* FileNameIsTooLong::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(ownTextLength + fileName.length());
    return &instance;
}

void FileNameIsTooLong::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}