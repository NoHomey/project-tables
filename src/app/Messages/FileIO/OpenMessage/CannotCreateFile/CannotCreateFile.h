#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class CannotCreateFile: public FileIOMessage {
public:
    static CannotCreateFile* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    CannotCreateFile() noexcept = default;

    CannotCreateFile(const CannotCreateFile& other) = delete;

    CannotCreateFile(CannotCreateFile&& other) = delete;

    CannotCreateFile& operator=(const CannotCreateFile& other) = delete;

    CannotCreateFile& operator=(CannotCreateFile&& other) = delete;

private:
    static CannotCreateFile instance;

    static ConstString textBeginning;
    
    static ConstString textEnding;
    
    static const size_t ownTextLength;
};