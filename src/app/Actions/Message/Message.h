#pragma once

#include "../Action/Action.h"
#include "../../../Components/Info/InfoModel/InfoModel.h"

class Message: public Action {
public:
    static Action* showMessage(InfoModel* message) noexcept;

    Action* action() final;

private:
    Message() noexcept = default;

private:
    static Message instance;

private:
    InfoModel* message = nullptr;
};