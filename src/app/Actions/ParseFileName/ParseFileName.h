#pragma once

#include "../Action/Action.h"
#include "../../../String/ConstString/ConstString.h"

class ParseFileName: public Action {
public:
    ParseFileName() noexcept = default;

    ParseFileName(const ParseFileName& other) = delete;

    ParseFileName(ParseFileName&& other) = delete;

    ParseFileName& operator=(const ParseFileName& other) = delete;

    ParseFileName& operator=(ParseFileName&& other) = delete;

public:
    static bool parseFileName(ConstString& commandName);

public:
    Action* action() final;
};
