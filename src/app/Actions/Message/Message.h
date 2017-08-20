#pragma once

#include "../Action/Action.h"
#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"

class Message: public Action {
public:
    static Action* showMessage(InfoModel* message) noexcept;

    Action* action() final;

private:
    Message() noexcept = default;

public:
    static const unsigned char mappedArgumentIndexNamesCount = 6;

    static ConstString mappedArgumentIndexNames[mappedArgumentIndexNamesCount];

private:
    static Message instance;

private:
    InfoModel* message = nullptr;
};