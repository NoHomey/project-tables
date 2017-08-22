#include "CannotWrite.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

CannotWrite CannotWrite::instance;

ConstString CannotWrite::text{"Write Error: writing became unsuitable for file: "};

CannotWrite* CannotWrite::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(text.length() + fileName.length());
    return &instance;
}

void CannotWrite::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}