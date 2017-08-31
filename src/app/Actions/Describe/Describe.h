#pragma once

#include "../ActionUsingOnlyTable/ActionUsingOnlyTable.htd"

class Describe: public ActionUsingOnlyTable<Describe> {
private:
    friend ActionUsingOnlyTable<Describe>;

    using Base = ActionUsingOnlyTable<Describe>;

public:
    static Action* controller() noexcept;

private:
    Describe() noexcept = default;

private:
    static void finalAction();

public:
    static ConstString actionString;

    static ConstString description;

private:
    static Describe instance;
};
