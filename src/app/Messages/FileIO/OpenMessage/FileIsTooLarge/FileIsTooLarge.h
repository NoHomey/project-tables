#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileIsTooLarge: public FileIOMessage {
public:
    FileIsTooLarge(const String& fileName);

    FileIsTooLarge(const FileIsTooLarge& other) = delete;

    FileIsTooLarge(FileIsTooLarge&& other) = delete;

    FileIsTooLarge& operator=(const FileIsTooLarge& other) = delete;

    FileIsTooLarge& operator=(FileIsTooLarge&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;
    
    static ConstString textEnding;

    static const size_t ownTextLength;
};