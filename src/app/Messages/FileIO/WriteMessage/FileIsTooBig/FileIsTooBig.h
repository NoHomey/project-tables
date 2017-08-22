#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileIsTooBig: public FileIOMessage {
public:
    FileIsTooBig(const String& fileName);

    FileIsTooBig(const FileIsTooBig& other) = delete;

    FileIsTooBig(FileIsTooBig&& other) = delete;

    FileIsTooBig& operator=(const FileIsTooBig& other) = delete;

    FileIsTooBig& operator=(FileIsTooBig&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;
    
    static ConstString textEnding;

    static const size_t ownTextLength;
};