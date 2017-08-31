#pragma once

#include "../Action/Action.h"
#include "../../../Components/Info/InfoModel/InfoModel.h"

class Help: public Action {
public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Help() noexcept = default;

public:
    static ConstString actionString;

    static ConstString description;

private:
    static Help instance;

private:
    class Description: public InfoModel {
    public:
        Description(ConstString& description) noexcept;

    public:
        void output(CharOutputStream& outputStream) const;

    private:
        ConstString& description;
    };
};