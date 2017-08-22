#include "ItIsADirectory.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ItIsADirectory ItIsADirectory::instance;

ConstString ItIsADirectory::textBeginning{"Open Error: file name: "};

ConstString ItIsADirectory::textEnding{" refers to directory not to file."};

const size_t ItIsADirectory::ownTextLength = textBeginning.length() + textEnding.length();

ItIsADirectory* ItIsADirectory::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(ownTextLength + fileName.length());
    return &instance;
}

void ItIsADirectory::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}