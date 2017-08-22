#include "CannotWrite.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString CannotWrite::text{"Write Error: writing became unsuitable for file: "};

CannotWrite::CannotWrite(const String& fileName)
: FileIOMessage{fileName, text.length()} { }

void CannotWrite::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}