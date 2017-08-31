#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"

class WelcomeInfo: public InfoModel {
public:
    static WelcomeInfo* welcomeInfo();

public:
    void output(CharOutputStream& outputStream) const final;

private:
    WelcomeInfo() noexcept;

    WelcomeInfo(const WelcomeInfo& other) = delete;

    WelcomeInfo(WelcomeInfo&& other) = delete;

    WelcomeInfo& operator=(const WelcomeInfo& other) = delete;

    WelcomeInfo& operator=(WelcomeInfo&& other) = delete;

private:
    static ConstString text;

    static WelcomeInfo instance;
};