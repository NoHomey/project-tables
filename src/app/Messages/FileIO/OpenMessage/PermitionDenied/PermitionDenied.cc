#include "PermitionDenied.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

PermitionDenied PermitionDenied::instance;

ConstString PermitionDenied::text{"Open Error: write access permition denied for file: "};

PermitionDenied* PermitionDenied::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(text.length() + fileName.length());
    return &instance;
}

void PermitionDenied::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}