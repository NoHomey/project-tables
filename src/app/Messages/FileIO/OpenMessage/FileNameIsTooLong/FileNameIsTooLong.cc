#include "FileNameIsTooLong.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString FileNameIsTooLong::textBeginning{"Open Error: file name: "};

ConstString FileNameIsTooLong::textEnding{" is too long."};

const size_t FileNameIsTooLong::ownTextLength = textBeginning.length() + textEnding.length();

FileNameIsTooLong::FileNameIsTooLong(const String& fileName)
: FileIOMessage{fileName, ownTextLength} { }

void FileNameIsTooLong::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}