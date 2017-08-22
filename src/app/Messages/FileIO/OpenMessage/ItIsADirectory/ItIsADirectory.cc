#include "ItIsADirectory.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString ItIsADirectory::textBeginning{"Open Error: file name: "};

ConstString ItIsADirectory::textEnding{" refers to directory not to file."};

const size_t ItIsADirectory::ownTextLength = textBeginning.length() + textEnding.length();

ItIsADirectory::ItIsADirectory(const String& fileName)
: FileIOMessage{fileName, ownTextLength} { }

void ItIsADirectory::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}