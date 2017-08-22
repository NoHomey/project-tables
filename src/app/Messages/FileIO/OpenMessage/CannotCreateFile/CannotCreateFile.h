#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class CannotCreateFile: public FileIOMessage {
public:
    CannotCreateFile(const String& fileName);

    CannotCreateFile(const CannotCreateFile& other) = delete;

    CannotCreateFile(CannotCreateFile&& other) = delete;

    CannotCreateFile& operator=(const CannotCreateFile& other) = delete;

    CannotCreateFile& operator=(CannotCreateFile&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;
    
    static ConstString textEnding;

    static const size_t ownTextLength;
};