#pragma once

#include "../Action/Action.h"
#include "../../../String/ConstString/ConstString.h"

class ParseTableName: public Action {
public:
    ParseTableName(ConstString& commandName) noexcept;

    ParseTableName(const ParseTableName& other) = delete;

    ParseTableName(ParseTableName&& other) = delete;

    ParseTableName& operator=(const ParseTableName& other) = delete;

    ParseTableName& operator=(ParseTableName&& other) = delete;

public:
    Action* action() final;

private:
    ConstString& commandName;
};
