#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileNameIsTooLong: public FileIOMessage {
public:
    static FileNameIsTooLong* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    FileNameIsTooLong() noexcept = default;

    FileNameIsTooLong(const FileNameIsTooLong& other) = delete;

    FileNameIsTooLong(FileNameIsTooLong&& other) = delete;

    FileNameIsTooLong& operator=(const FileNameIsTooLong& other) = delete;

    FileNameIsTooLong& operator=(FileNameIsTooLong&& other) = delete;

private:
    static FileNameIsTooLong instance;

    static ConstString textBeginning;
    
    static ConstString textEnding;
    
    static const size_t ownTextLength;
};