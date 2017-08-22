#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class UnexpectedWriteError: public FileIOMessage {
public:
    UnexpectedWriteError(const String& fileName);

    UnexpectedWriteError(const UnexpectedWriteError& other) = delete;

    UnexpectedWriteError(UnexpectedWriteError&& other) = delete;

    UnexpectedWriteError& operator=(const UnexpectedWriteError& other) = delete;

    UnexpectedWriteError& operator=(UnexpectedWriteError&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString text;
};