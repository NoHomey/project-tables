#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileSystemDiskBlocksQuotaExhausted: public FileIOMessage {
public:
    FileSystemDiskBlocksQuotaExhausted(const String& fileName);

    FileSystemDiskBlocksQuotaExhausted(const FileSystemDiskBlocksQuotaExhausted& other) = delete;

    FileSystemDiskBlocksQuotaExhausted(FileSystemDiskBlocksQuotaExhausted&& other) = delete;

    FileSystemDiskBlocksQuotaExhausted& operator=(const FileSystemDiskBlocksQuotaExhausted& other) = delete;

    FileSystemDiskBlocksQuotaExhausted& operator=(FileSystemDiskBlocksQuotaExhausted&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString text;
};