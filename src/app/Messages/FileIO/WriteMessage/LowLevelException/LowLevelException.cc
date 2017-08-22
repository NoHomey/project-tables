#include "LowLevelException.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString LowLevelException::text{"Write Error: low-level (probably hardware) error occurred while writing to file: "};

LowLevelException::LowLevelException(const String& fileName)
: FileIOMessage{fileName, text.length()} { }

void LowLevelException::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}