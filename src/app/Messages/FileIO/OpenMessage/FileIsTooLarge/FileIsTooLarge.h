#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileIsTooLarge: public FileIOMessage {
public:
    static FileIsTooLarge* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    FileIsTooLarge() noexcept = default;

    FileIsTooLarge(const FileIsTooLarge& other) = delete;

    FileIsTooLarge(FileIsTooLarge&& other) = delete;

    FileIsTooLarge& operator=(const FileIsTooLarge& other) = delete;

    FileIsTooLarge& operator=(FileIsTooLarge&& other) = delete;

private:
    static FileIsTooLarge instance;

    static ConstString textBeginning;
    
    static ConstString textEnding;
    
    static const size_t ownTextLength;
};