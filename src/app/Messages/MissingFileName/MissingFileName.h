#pragma once

#include "../MissingArgument/MissingArgument.h"

class MissingFileName: public MissingArgument {
public:
    static MissingFileName* inject(ConstString& command, ConstString& argument) noexcept;

private:
    MissingFileName() noexcept;

    MissingFileName(const MissingFileName& other) = delete;

    MissingFileName(MissingFileName&& other) = delete;

    MissingFileName& operator=(const MissingFileName& other) = delete;

    MissingFileName& operator=(MissingFileName&& other) = delete;

private:
    static ConstString fileName;

    static MissingFileName instance;
};