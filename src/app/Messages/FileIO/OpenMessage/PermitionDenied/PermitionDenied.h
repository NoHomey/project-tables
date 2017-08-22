#pragma once

#include "../../FileIOMessage/FileIOMessage.h"

class PermitionDenied: public FileIOMessage {
public:
    static PermitionDenied* inject(const String& fileName);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    PermitionDenied() noexcept = default;

    PermitionDenied(const PermitionDenied& other) = delete;

    PermitionDenied(PermitionDenied&& other) = delete;

    PermitionDenied& operator=(const PermitionDenied& other) = delete;

    PermitionDenied& operator=(PermitionDenied&& other) = delete;

private:
    static PermitionDenied instance;

    static ConstString text;
};