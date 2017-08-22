#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class PermitionDenied: public FileIOMessage {
public:
    PermitionDenied(const String& fileName);

    PermitionDenied(const PermitionDenied& other) = delete;

    PermitionDenied(PermitionDenied&& other) = delete;

    PermitionDenied& operator=(const PermitionDenied& other) = delete;

    PermitionDenied& operator=(PermitionDenied&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString text;
};