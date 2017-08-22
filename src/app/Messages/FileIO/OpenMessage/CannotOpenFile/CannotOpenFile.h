#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class CannotOpenFile: public FileIOMessage {
public:
    CannotOpenFile(const String& fileName);

    CannotOpenFile(const CannotOpenFile& other) = delete;

    CannotOpenFile(CannotOpenFile&& other) = delete;

    CannotOpenFile& operator=(const CannotOpenFile& other) = delete;

    CannotOpenFile& operator=(CannotOpenFile&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;
    
    static ConstString textEnding;

    static const size_t ownTextLength;
};