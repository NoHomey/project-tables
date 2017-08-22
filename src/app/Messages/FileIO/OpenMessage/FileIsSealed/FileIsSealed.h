#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileIsSealed: public FileIOMessage {
public:
    static FileIsSealed* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    FileIsSealed() noexcept = default;

    FileIsSealed(const FileIsSealed& other) = delete;

    FileIsSealed(FileIsSealed&& other) = delete;

    FileIsSealed& operator=(const FileIsSealed& other) = delete;

    FileIsSealed& operator=(FileIsSealed&& other) = delete;

private:
    static FileIsSealed instance;

    static ConstString textBeginning;
    
    static ConstString textEnding;
    
    static const size_t ownTextLength;
};