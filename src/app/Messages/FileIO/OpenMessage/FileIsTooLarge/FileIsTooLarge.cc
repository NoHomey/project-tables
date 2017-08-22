#include "FileIsTooLarge.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString FileIsTooLarge::textBeginning{"Open Error: file: "};

ConstString FileIsTooLarge::textEnding{" is too large."};

const size_t FileIsTooLarge::ownTextLength = textBeginning.length() + textEnding.length();

FileIsTooLarge::FileIsTooLarge(const String& fileName)
: FileIOMessage{fileName, ownTextLength} { }

void FileIsTooLarge::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}