#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileSystemDiskBlocksQuotaExhausted: public FileIOMessage {
public:
    static FileSystemDiskBlocksQuotaExhausted* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    FileSystemDiskBlocksQuotaExhausted() noexcept = default;

    FileSystemDiskBlocksQuotaExhausted(const FileSystemDiskBlocksQuotaExhausted& other) = delete;

    FileSystemDiskBlocksQuotaExhausted(FileSystemDiskBlocksQuotaExhausted&& other) = delete;

    FileSystemDiskBlocksQuotaExhausted& operator=(const FileSystemDiskBlocksQuotaExhausted& other) = delete;

    FileSystemDiskBlocksQuotaExhausted& operator=(FileSystemDiskBlocksQuotaExhausted&& other) = delete;

private:
    static FileSystemDiskBlocksQuotaExhausted instance;

    static ConstString text;
};