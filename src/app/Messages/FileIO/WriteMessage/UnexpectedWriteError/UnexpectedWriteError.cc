#include "UnexpectedWriteError.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString UnexpectedWriteError::text{"Write Error: unexpected error occurred while writing to file: "};

UnexpectedWriteError::UnexpectedWriteError(const String& fileName)
: FileIOMessage{fileName, text.length()} { }

void UnexpectedWriteError::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}