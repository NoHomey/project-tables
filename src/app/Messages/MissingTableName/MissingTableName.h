#pragma once

#include "../MissingArgument/MissingArgument.h"

class MissingTableName: public MissingArgument {
public:
    MissingTableName(ConstString& command, unsigned int argument) noexcept;

    MissingTableName(const MissingTableName& other) = delete;

    MissingTableName(MissingTableName&& other) = delete;

    MissingTableName& operator=(const MissingTableName& other) = delete;

    MissingTableName& operator=(MissingTableName&& other) = delete;

private:
    static ConstString tableNameIdentificator;
};