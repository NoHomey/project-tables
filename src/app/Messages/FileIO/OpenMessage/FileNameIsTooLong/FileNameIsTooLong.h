#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileNameIsTooLong: public FileIOMessage {
public:
    FileNameIsTooLong(const String& fileName);

    FileNameIsTooLong(const FileNameIsTooLong& other) = delete;

    FileNameIsTooLong(FileNameIsTooLong&& other) = delete;

    FileNameIsTooLong& operator=(const FileNameIsTooLong& other) = delete;

    FileNameIsTooLong& operator=(FileNameIsTooLong&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;
    
    static ConstString textEnding;

    static const size_t ownTextLength;
};