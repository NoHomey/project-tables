#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileIsLocatedOnReadOnlyFileSystem: public FileIOMessage {
public:
    FileIsLocatedOnReadOnlyFileSystem(const String& fileName);

    FileIsLocatedOnReadOnlyFileSystem(const FileIsLocatedOnReadOnlyFileSystem& other) = delete;

    FileIsLocatedOnReadOnlyFileSystem(FileIsLocatedOnReadOnlyFileSystem&& other) = delete;

    FileIsLocatedOnReadOnlyFileSystem& operator=(const FileIsLocatedOnReadOnlyFileSystem& other) = delete;

    FileIsLocatedOnReadOnlyFileSystem& operator=(FileIsLocatedOnReadOnlyFileSystem&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;
    
    static ConstString textEnding;

    static const size_t ownTextLength;
};