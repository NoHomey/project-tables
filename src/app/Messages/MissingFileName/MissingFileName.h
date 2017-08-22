#pragma once

#include "../MissingArgument/MissingArgument.h"

class MissingFileName: public MissingArgument {
public:
    MissingFileName(ConstString& command, unsigned int argument) noexcept;

    MissingFileName(const MissingFileName& other) = delete;

    MissingFileName(MissingFileName&& other) = delete;

    MissingFileName& operator=(const MissingFileName& other) = delete;

    MissingFileName& operator=(MissingFileName&& other) = delete;

private:
    static ConstString fileNameArgument;
};