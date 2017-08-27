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

    class Commands {
    public:
        Commands() noexcept = default;
    
        Commands(size_t count);
    
        Commands(Commands&& other) noexcept = default;
    
        Commands& operator=(Commands&& other) noexcept = default;
    
    public:
        template<typename Type>
        void registerCommand();
    
        DynamicArray<ActionCommand>& getCommands() noexcept;
    
    private:
        DynamicArray<ActionCommand> commands;
    };

public:
    static void reRender();

    static void takeAction(ConstString& command);

    static void registerCommands(Commands&& commands) noexcept;

public:
    virtual Action* action() = 0;

    virtual Action* controlAction() noexcept;

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

    static Commands commands;

private:
    static Action* selectAction(ConstString& action);

    static void nullArguments() noexcept;

private:
    static const size_t ArgumentsIntialCapacity = 6; 
};

template<typename Type>
void Action::Commands::registerCommand() {
    commands.push({Type::actionString, Type::controller()});
}