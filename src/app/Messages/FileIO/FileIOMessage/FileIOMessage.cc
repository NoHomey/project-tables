#include "FileIOMessage.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

void FileIOMessage::releaseResources() noexcept {
    fileName = {};
}

void FileIOMessage::setFileName(const String& name) {
    fileName = FixedSizeString::fromString(name);
}

void FileIOMessage::outputFileName(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, fileName);
}