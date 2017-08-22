#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class UnexpectedWriteError: public FileIOMessage {
public:
    static UnexpectedWriteError* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    UnexpectedWriteError() noexcept = default;

    UnexpectedWriteError(const UnexpectedWriteError& other) = delete;

    UnexpectedWriteError(UnexpectedWriteError&& other) = delete;

    UnexpectedWriteError& operator=(const UnexpectedWriteError& other) = delete;

    UnexpectedWriteError& operator=(UnexpectedWriteError&& other) = delete;

private:
    static UnexpectedWriteError instance;

    static ConstString text;
};