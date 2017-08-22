#include "UnexpectedWriteError.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

UnexpectedWriteError UnexpectedWriteError::instance;

ConstString UnexpectedWriteError::text{"Write Error: unexpected error occurred while writing to file: "};

UnexpectedWriteError* UnexpectedWriteError::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(text.length() + fileName.length());
    return &instance;
}

void UnexpectedWriteError::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}