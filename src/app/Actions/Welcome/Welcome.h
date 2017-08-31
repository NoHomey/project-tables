#pragma once

#include "../Action/Action.h"

class Welcome: public Action {
public:
    Welcome() noexcept = default;

    Welcome(const Welcome& other) = delete;

    Welcome(Welcome&& other) = delete;

    Welcome& operator=(const Welcome& other) = delete;

    Welcome& operator=(Welcome&& other) = delete;

public:
    static void showWelcome();

public:
    Action* action() final;
};
