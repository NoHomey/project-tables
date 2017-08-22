#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class FileIsTooBig: public FileIOMessage {
public:
    static FileIsTooBig* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    FileIsTooBig() noexcept = default;

    FileIsTooBig(const FileIsTooBig& other) = delete;

    FileIsTooBig(FileIsTooBig&& other) = delete;

    FileIsTooBig& operator=(const FileIsTooBig& other) = delete;

    FileIsTooBig& operator=(FileIsTooBig&& other) = delete;

private:
    static FileIsTooBig instance;

    static ConstString textBeginning;
    
    static ConstString textEnding;
    
    static const size_t ownTextLength;
};