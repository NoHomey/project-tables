#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class LowLevelException: public FileIOMessage {
public:
    LowLevelException(const String& fileName);
    
    LowLevelException(const LowLevelException& other) = delete;

    LowLevelException(LowLevelException&& other) = delete;

    LowLevelException& operator=(const LowLevelException& other) = delete;

    LowLevelException& operator=(LowLevelException&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString text;
};