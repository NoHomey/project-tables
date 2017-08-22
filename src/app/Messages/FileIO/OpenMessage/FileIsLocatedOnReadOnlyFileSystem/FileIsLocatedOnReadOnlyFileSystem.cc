#include "FileIsLocatedOnReadOnlyFileSystem.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

FileIsLocatedOnReadOnlyFileSystem FileIsLocatedOnReadOnlyFileSystem::instance;

ConstString FileIsLocatedOnReadOnlyFileSystem::textBeginning{"Open Error: file: "};

ConstString FileIsLocatedOnReadOnlyFileSystem::textEnding{" is located on read-only file system and can not be open for writing."};

const size_t FileIsLocatedOnReadOnlyFileSystem::ownTextLength = textBeginning.length() + textEnding.length();

FileIsLocatedOnReadOnlyFileSystem* FileIsLocatedOnReadOnlyFileSystem::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(ownTextLength + fileName.length());
    return &instance;
}

void FileIsLocatedOnReadOnlyFileSystem::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}