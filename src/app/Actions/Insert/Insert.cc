#include "Insert.h"
#include "../../../Parsers/IntegerParser/IntegerParser.h"
#include "../../../Parsers/FractionalNumberParser/FractionalNumberParser.h"
#include "../../../Parsers/StringParser/StringParser.h"
#include "../../Messages/WrongNumberOfColumns/WrongNumberOfColumns.h"
#include "../../Messages/InsertIntoTableWithNoColumns/InsertIntoTableWithNoColumns.h"
#include "../../Messages/InsertedIntoTable/InsertedIntoTable.h"

Insert Insert:: instance;

ConstString Insert::actionString{"Insert"};

Insert::Insert() noexcept
: Base{InsertState::ParseTableName} { }

Action* Insert::controller() noexcept {
    return &instance;
}

Action* Insert::parseTableName() {
    return Base::parseTableName<Insert>(InsertState::RemoveTableNameFromArguments, InsertState::TableNotFound);
}

Action* Insert::removeTableNameFromArguments() {
    arguments.pop();
    setState(InsertState::ParseValue);
    return this;
}

Action* Insert::parseInteger() {
    IntegerParser::ParseResult result;
    try {
        result = IntegerParser::parse(command);
    } catch(const Exception&) {
        setState(InsertState::MissingValue);
        return this;
    }
    Action::command = result.getRest();
    arguments.push(result.getParsed());
    return this;
}

Action* Insert::parseFractionalNumber() {
    FractionalNumberParser::ParseResult result;
    try {
        result = FractionalNumberParser::parse(command);
    } catch(const Exception&) {
        setState(InsertState::MissingValue);
        return this;
    }
    Action::command = result.getRest();
    arguments.push(result.getParsed());
    return this;
}

Action* Insert::parseString() {
    StringParser::ParseResult result;
    try {
        result = StringParser::parse(command);
    } catch(const Exception&) {
        setState(InsertState::MissingValue);
        return this;
    }
    Action::command = result.getRest();
    arguments.push(std::move(result.moveParsed()));
    return this;
}

Action* Insert::missingValue() {
    showMessage(new WrongNumberOfColumns(*currentTable, arguments.size()));
    return nullptr;
}

Action* Insert::parseValue() {
    if(arguments.size() == currentTable->columnsCount()) {
        setState(InsertState::Insert);
        return this;
    }
    switch(currentTable->getColumnsMetaData()[arguments.size()].getType()) {
        case ColumnMetaData::ColumnType::Integer: return parseInteger();
        case ColumnMetaData::ColumnType::FractionalNumber: return parseFractionalNumber();
        case ColumnMetaData::ColumnType::String: return parseString();
        default: return this;
    }
}

Action* Insert::insert() {
    if(arguments.isEmpty()) {
        return showMessage(new InsertIntoTableWithNoColumns(currentTable->getName()));
    }
    const TableTypes::Column columnsCount = currentTable->columnsCount();
    TableData& data = currentTable->data();
    for(TableTypes::Column column = 0; column < columnsCount; ++column) {
        Argument& argument = arguments[column];
        switch(argument.getType()) {
            case Argument::ArgumentType::Integer:
                data.insert(argument.asInteger());
                break;
            case Argument::ArgumentType::FractionalNumber:
                data.insert(argument.asFractionalNumber());
                break;
            case Argument::ArgumentType::String:
                data.insert(std::move(argument.moveString()));
                break;
            default: break; // message
        }
    }
    return showMessage(new InsertedIntoTable(currentTable->getName()));
}

Action* Insert::action() {
    switch(getState()) {
        case InsertState::ParseTableName: return parseTableName();
        case InsertState::TableNotFound: return tableNotFound();
        case InsertState::RemoveTableNameFromArguments: return removeTableNameFromArguments();
        case InsertState::ParseValue: return parseValue();
        case InsertState::MissingValue: return missingValue();
        case InsertState::Insert: return insert();
        default: return nullptr;
    };
}

Action* Insert::controlAction() noexcept {
    setState(InsertState::ParseTableName);
    return this;
}