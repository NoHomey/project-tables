#include "PermitionDenied.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString PermitionDenied::text{"Open Error: write access permition denied for file: "};

PermitionDenied::PermitionDenied(const String& fileName)
: FileIOMessage{fileName, text.length()} { }

void PermitionDenied::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}