#include "FileIsSealed.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString FileIsSealed::textBeginning{"Open Error: file: "};

ConstString FileIsSealed::textEnding{" is sealed."};

const size_t FileIsSealed::ownTextLength = textBeginning.length() + textEnding.length();

FileIsSealed::FileIsSealed(const String& fileName)
: FileIOMessage{fileName, ownTextLength} { }

void FileIsSealed::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}