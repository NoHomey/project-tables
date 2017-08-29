#pragma once

#include "../MissingArgument/MissingArgument.h"

class MissingColumnValue: public MissingArgument {
public:
    MissingColumnValue(ConstString& command, unsigned int argument) noexcept;

    MissingColumnValue(const MissingColumnValue& other) = delete;

    MissingColumnValue(MissingColumnValue&& other) = delete;

    MissingColumnValue& operator=(const MissingColumnValue& other) = delete;

    MissingColumnValue& operator=(MissingColumnValue&& other) = delete;

private:
    static ConstString fileNameArgument;
};