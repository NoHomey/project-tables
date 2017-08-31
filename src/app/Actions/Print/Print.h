#pragma once

#include "../ActionUsingOnlyTable/ActionUsingOnlyTable.htd"

class Print: public ActionUsingOnlyTable<Print> {
private:
    friend ActionUsingOnlyTable<Print>;

    using Base = ActionUsingOnlyTable<Print>;

public:
    static Action* controller() noexcept;

private:
    Print() noexcept = default;

private:
    static void finalAction();

public:
    static ConstString actionString;

private:
    static Print instance;
};
