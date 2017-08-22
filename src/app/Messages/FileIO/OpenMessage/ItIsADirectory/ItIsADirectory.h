#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class ItIsADirectory: public FileIOMessage {
public:
    static ItIsADirectory* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    ItIsADirectory() noexcept = default;

    ItIsADirectory(const ItIsADirectory& other) = delete;

    ItIsADirectory(ItIsADirectory&& other) = delete;

    ItIsADirectory& operator=(const ItIsADirectory& other) = delete;

    ItIsADirectory& operator=(ItIsADirectory&& other) = delete;

private:
    static ItIsADirectory instance;

    static ConstString textBeginning;
    
    static ConstString textEnding;
    
    static const size_t ownTextLength;
};