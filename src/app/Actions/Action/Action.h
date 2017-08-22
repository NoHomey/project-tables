#pragma once

#include "../../../Tables/Tables.h"
#include "../../../Components/Component.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "Argument/Argument.h"

class Action {
public:
    class ActionCommand {
    public:
        ActionCommand() noexcept;

        ActionCommand(ConstString& command, Action* const action) noexcept;

        ConstString& getCommand() const noexcept;

        Action* getAction() noexcept;

    private:
        ImmutableString command;

        Action* action;
    };

public:
    static void reRender();

    static void takeAction(ConstString& command);

    static void registerCommands(DynamicArray<ActionCommand>&& commands) noexcept;

    static const DynamicArray<ActionCommand>& getCommands() noexcept;

public:
    virtual Action* action() = 0;

public:
    virtual ~Action() noexcept = default;

protected:
    static Action* showMessage(const InfoModel* model) noexcept;

protected:
    static void setCurrentTable(Table* currentTable) noexcept;
    
    static void setComponent(Component* component) noexcept;

protected:
    static Tables allTables;

    static Table* currentTable;

    static Component* component;

    static ImmutableString command;

    static MoveDynamicArray<Argument> arguments;

    static DynamicArray<ActionCommand> commands;

private:
    static Action* selectAction(ConstString& action);

    static void nullArguments() noexcept;

private:
    static const size_t ArgumentsIntialCapacity = 6; 
};