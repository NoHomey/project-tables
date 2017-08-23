#pragma once

#include "../Action/Action.h"
#include "../../../String/ConstString/ConstString.h"

class ParseFileName: public Action {
public:
    ParseFileName(ConstString& commandName) noexcept;

    ParseFileName(const ParseFileName& other) = delete;

    ParseFileName(ParseFileName&& other) = delete;

    ParseFileName& operator=(const ParseFileName& other) = delete;

    ParseFileName& operator=(ParseFileName&& other) = delete;

public:
    Action* action() final;

private:
    ConstString& commandName;
};
