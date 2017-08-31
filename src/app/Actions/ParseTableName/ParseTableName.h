#pragma once

#include "../Action/Action.h"
#include "../../../String/ConstString/ConstString.h"

class ParseTableName: public Action {
public:
    ParseTableName() noexcept = default;

    ParseTableName(const ParseTableName& other) = delete;

    ParseTableName(ParseTableName&& other) = delete;

    ParseTableName& operator=(const ParseTableName& other) = delete;

    ParseTableName& operator=(ParseTableName&& other) = delete;

public:
    static bool parseTableName(ConstString& commandName);

public:
    Action* action() final;
};
