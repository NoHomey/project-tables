#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileIsSealed: public FileIOMessage {
public:
    FileIsSealed(const String& fileName);

    FileIsSealed(const FileIsSealed& other) = delete;

    FileIsSealed(FileIsSealed&& other) = delete;

    FileIsSealed& operator=(const FileIsSealed& other) = delete;

    FileIsSealed& operator=(FileIsSealed&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;
    
    static ConstString textEnding;

    static const size_t ownTextLength;
};