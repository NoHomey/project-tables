#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class CannotWrite: public FileIOMessage {
public:
    CannotWrite(const String& fileName);

    CannotWrite(const CannotWrite& other) = delete;

    CannotWrite(CannotWrite&& other) = delete;

    CannotWrite& operator=(const CannotWrite& other) = delete;

    CannotWrite& operator=(CannotWrite&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString text;
};