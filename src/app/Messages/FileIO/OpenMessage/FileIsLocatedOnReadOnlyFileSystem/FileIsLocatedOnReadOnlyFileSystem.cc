#include "FileIsLocatedOnReadOnlyFileSystem.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString FileIsLocatedOnReadOnlyFileSystem::textBeginning{"Open Error: file: "};

ConstString FileIsLocatedOnReadOnlyFileSystem::textEnding{" is located on read-only file system and can not be open for writing."};

const size_t FileIsLocatedOnReadOnlyFileSystem::ownTextLength = textBeginning.length() + textEnding.length();

FileIsLocatedOnReadOnlyFileSystem::FileIsLocatedOnReadOnlyFileSystem(const String& fileName)
: FileIOMessage{fileName, ownTextLength} { }

void FileIsLocatedOnReadOnlyFileSystem::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputFileName(outputStream);
    TypesOutputer::output(outputStream, textEnding);
}