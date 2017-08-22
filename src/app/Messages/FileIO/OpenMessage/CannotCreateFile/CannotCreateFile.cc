#include "CannotCreateFile.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

CannotCreateFile CannotCreateFile::instance;

ConstString CannotCreateFile::textBeginning{"Open Error: file: "};

ConstString CannotCreateFile::textEnding{" dose not exist and it can not be created."};

const size_t CannotCreateFile::ownTextLength = textBeginning.length() + textEnding.length();

CannotCreateFile* CannotCreateFile::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(ownTextLength + fileName.length());
    return &instance;
}

void CannotCreateFile::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}