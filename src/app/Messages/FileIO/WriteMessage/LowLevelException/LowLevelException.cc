#include "LowLevelException.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

LowLevelException LowLevelException::instance;

ConstString LowLevelException::text{"Write Error: low-level (probably hardware) error occurred while writing to file: "};

LowLevelException* LowLevelException::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(text.length() + fileName.length());
    return &instance;
}

void LowLevelException::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}