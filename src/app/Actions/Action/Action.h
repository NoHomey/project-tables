#pragma once

#include "../../../Tables/Tables.h"
#include "../../../Components/Component.h"
#include "../../../String/ConstString/ConstString.h"
#include "Argument/Argument.h"

class Action {
public:
    static void reRender();

    static void takeAction(ConstString& command);

    static void __mock();

public:
    virtual Action* action() = 0;

    void setCurrentTable(Table* currentTable) noexcept;

    void setComponent(Component* component) noexcept;

public:
    virtual ~Action() noexcept = default;

protected:
    static Tables allTables;

    static Table* currentTable;

    static Component* component;

    static ImmutableString command;

    static MoveDynamicArray<Argument> arguments;

private:
    static Action* selectAction(ConstString& action);

    static void nullArguments() noexcept;

private:
    static const size_t ArgumentsIntialCapacity = 6; 
};
