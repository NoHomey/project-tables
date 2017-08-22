#include "FileIOMessage.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

FileIOMessage::FileIOMessage(const String& fileName, size_t textLength)
: InfoModel{textLength + fileName.length(), true}, fileName{FixedSizeString::fromString(fileName)} { }

void FileIOMessage::outputFileName(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, fileName);
}