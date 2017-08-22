#pragma once

#include "../Action/Action.h"
#include "../../../String/ConstString/ConstString.h"

class ParseFileName: public Action {
public:
    static Action* parseFileName(ConstString& commandName) noexcept;

    Action* action() final;

private:
    ParseFileName() noexcept = default;

    ParseFileName(const ParseFileName& other) = delete;

    ParseFileName(ParseFileName&& other) = delete;

    ParseFileName& operator=(const ParseFileName& other) = delete;

    ParseFileName& operator=(ParseFileName&& other) = delete;

private:
    static ParseFileName instance;

private:
    ImmutableString commandName;
};
