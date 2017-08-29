#pragma once

#include "../MissingArgument/MissingArgument.h"

class MissingColumnNumber: public MissingArgument {
public:
    MissingColumnNumber(ConstString& command, unsigned int argument) noexcept;

    MissingColumnNumber(const MissingColumnNumber& other) = delete;

    MissingColumnNumber(MissingColumnNumber&& other) = delete;

    MissingColumnNumber& operator=(const MissingColumnNumber& other) = delete;

    MissingColumnNumber& operator=(MissingColumnNumber&& other) = delete;

private:
    static ConstString fileNameArgument;
};