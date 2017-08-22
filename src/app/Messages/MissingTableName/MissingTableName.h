#pragma once

#include "../MissingArgument/MissingArgument.h"

class MissingTableName: public MissingArgument {
public:
    static MissingTableName* inject(ConstString& command, ConstString& argument) noexcept;

private:
    MissingTableName() noexcept;

    MissingTableName(const MissingTableName& other) = delete;

    MissingTableName(MissingTableName&& other) = delete;

    MissingTableName& operator=(const MissingTableName& other) = delete;

    MissingTableName& operator=(MissingTableName&& other) = delete;

private:
    static ConstString tableNameIdentificator;

    static MissingTableName instance;
};