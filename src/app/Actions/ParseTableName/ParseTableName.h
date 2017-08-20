#pragma once

#include "../Action/Action.h"
#include "../../../String/ConstString/ConstString.h"

class ParseTableName: public Action {
public:
    static Action* parseTableName(ConstString& commandName, unsigned char argument) noexcept;

    Action* action() final;

private:
    ParseTableName() noexcept = default;

    ParseTableName(const ParseTableName& other) = delete;

    ParseTableName(ParseTableName&& other) = delete;

    ParseTableName& operator=(const ParseTableName& other) = delete;

    ParseTableName& operator=(ParseTableName&& other) = delete;

private:
    static ParseTableName instance;

private:
    ImmutableString commandName;

    unsigned char argument;
};
