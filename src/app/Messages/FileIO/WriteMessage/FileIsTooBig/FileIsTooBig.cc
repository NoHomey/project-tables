#include "FileIsTooBig.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString FileIsTooBig::textBeginning{"Write Error: file content of: "};

ConstString FileIsTooBig::textEnding{" is so big that it can not be written."};

const size_t FileIsTooBig::ownTextLength = textBeginning.length() + textEnding.length();

FileIsTooBig::FileIsTooBig(const String& fileName)
: FileIOMessage{fileName, ownTextLength} { }

void FileIsTooBig::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}