#include "CannotOpenFile.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString CannotOpenFile::textBeginning{"Open Error: file: "};

ConstString CannotOpenFile::textEnding{" can not be opened."};

const size_t CannotOpenFile::ownTextLength = textBeginning.length() + textEnding.length();

CannotOpenFile::CannotOpenFile(const String& fileName)
: FileIOMessage{fileName, ownTextLength} { }

void CannotOpenFile::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}