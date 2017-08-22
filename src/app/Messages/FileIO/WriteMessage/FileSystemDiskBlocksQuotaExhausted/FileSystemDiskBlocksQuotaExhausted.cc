#include "FileSystemDiskBlocksQuotaExhausted.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

FileSystemDiskBlocksQuotaExhausted FileSystemDiskBlocksQuotaExhausted::instance;

ConstString FileSystemDiskBlocksQuotaExhausted::text{"Write Error: file system's disk blocks quota is or became exhausted while writing to file: "};


FileSystemDiskBlocksQuotaExhausted* FileSystemDiskBlocksQuotaExhausted::inject(const String& fileName) {
    instance.setFileName(fileName);
    instance.setTextLength(text.length() + fileName.length());
    return &instance;
}

void FileSystemDiskBlocksQuotaExhausted::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
    outputFileName(outputStream);
}