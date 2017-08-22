#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class CannotOpenFile: public FileIOMessage {
public:
    static CannotOpenFile* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    CannotOpenFile() noexcept = default;

    CannotOpenFile(const CannotOpenFile& other) = delete;

    CannotOpenFile(CannotOpenFile&& other) = delete;

    CannotOpenFile& operator=(const CannotOpenFile& other) = delete;

    CannotOpenFile& operator=(CannotOpenFile&& other) = delete;

private:
    static CannotOpenFile instance;

    static ConstString textBeginning;
    
    static ConstString textEnding;
    
    static const size_t ownTextLength;
};