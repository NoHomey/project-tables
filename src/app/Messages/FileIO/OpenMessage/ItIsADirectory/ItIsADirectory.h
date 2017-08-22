#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class ItIsADirectory: public FileIOMessage {
public:
    ItIsADirectory(const String& fileName);

    ItIsADirectory(const ItIsADirectory& other) = delete;

    ItIsADirectory(ItIsADirectory&& other) = delete;

    ItIsADirectory& operator=(const ItIsADirectory& other) = delete;

    ItIsADirectory& operator=(ItIsADirectory&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;
    
    static ConstString textEnding;

    static const size_t ownTextLength;
};