#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileIsLocatedOnReadOnlyFileSystem: public FileIOMessage {
public:
    static FileIsLocatedOnReadOnlyFileSystem* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    FileIsLocatedOnReadOnlyFileSystem() noexcept = default;

    FileIsLocatedOnReadOnlyFileSystem(const FileIsLocatedOnReadOnlyFileSystem& other) = delete;

    FileIsLocatedOnReadOnlyFileSystem(FileIsLocatedOnReadOnlyFileSystem&& other) = delete;

    FileIsLocatedOnReadOnlyFileSystem& operator=(const FileIsLocatedOnReadOnlyFileSystem& other) = delete;

    FileIsLocatedOnReadOnlyFileSystem& operator=(FileIsLocatedOnReadOnlyFileSystem&& other) = delete;

private:
    static FileIsLocatedOnReadOnlyFileSystem instance;

    static ConstString textBeginning;
    
    static ConstString textEnding;
    
    static const size_t ownTextLength;
};