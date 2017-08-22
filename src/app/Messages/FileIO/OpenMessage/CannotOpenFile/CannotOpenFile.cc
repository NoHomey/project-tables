#include "CannotOpenFile.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

CannotOpenFile CannotOpenFile::instance;

ConstString CannotOpenFile::textBeginning{"Open Error: file: "};

ConstString CannotOpenFile::textEnding{" can not be opened."};

const size_t CannotOpenFile::ownTextLength = textBeginning.length() + textEnding.length();

CannotOpenFile* CannotOpenFile::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(ownTextLength + fileName.length());
    return &instance;
}

void CannotOpenFile::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}