#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class CannotWrite: public FileIOMessage {
public:
    static CannotWrite* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    CannotWrite() noexcept = default;

    CannotWrite(const CannotWrite& other) = delete;

    CannotWrite(CannotWrite&& other) = delete;

    CannotWrite& operator=(const CannotWrite& other) = delete;

    CannotWrite& operator=(CannotWrite&& other) = delete;

private:
    static CannotWrite instance;

    static ConstString text;
};