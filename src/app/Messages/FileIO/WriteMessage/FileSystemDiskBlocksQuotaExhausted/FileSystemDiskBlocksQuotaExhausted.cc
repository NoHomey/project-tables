#include "FileSystemDiskBlocksQuotaExhausted.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString FileSystemDiskBlocksQuotaExhausted::text{"Write Error: file system's disk blocks quota is or became exhausted while writing to file: "};

FileSystemDiskBlocksQuotaExhausted::FileSystemDiskBlocksQuotaExhausted(const String& fileName)
: FileIOMessage{fileName, text.length()} { }

void FileSystemDiskBlocksQuotaExhausted::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}