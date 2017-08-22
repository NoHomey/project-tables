#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class LowLevelException: public FileIOMessage {
public:
    static LowLevelException* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    LowLevelException() noexcept = default;

    LowLevelException(const LowLevelException& other) = delete;

    LowLevelException(LowLevelException&& other) = delete;

    LowLevelException& operator=(const LowLevelException& other) = delete;

    LowLevelException& operator=(LowLevelException&& other) = delete;

private:
    static LowLevelException instance;

    static ConstString text;
};