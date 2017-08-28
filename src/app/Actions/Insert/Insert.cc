#include "Insert.h"
#include "../../../Parsers/IntegerParser/IntegerParser.h"
#include "../../../Parsers/FractionalNumberParser/FractionalNumberParser.h"
#include "../../../Parsers/StringParser/StringParser.h"
#include "../../Messages/Parsers/SingleSign/SingleSign.h"
#include "../../Messages/Parsers/InvalidInteger/InvalidInteger.h"
#include "../../Messages/Parsers/IntegerOutOfRange/IntegerOutOfRange.h"
#include "../../Messages/Parsers/SingleFloatingPoint/SingleFloatingPoint.h"
#include "../../Messages/Parsers/FractionalNumberHasNoIntegerPart/FractionalNumberHasNoIntegerPart.h"
#include "../../Messages/Parsers/FractionalNumberHasNoFractionalPart/FractionalNumberHasNoFractionalPart.h"
#include "../../Messages/Parsers/InvalidFractionalNumber/InvalidFractionalNumber.h"
#include "../../Messages/Parsers/FractionalNumberDigitsLimit/FractionalNumberDigitsLimit.h"
#include "../../Messages/Parsers/MissingDoubleQuotesInTheBeginning/MissingDoubleQuotesInTheBeginning.h"
#include "../../Messages/Parsers/MissingDoubleQuotesInTheEnd/MissingDoubleQuotesInTheEnd.h"
#include "../../Messages/Parsers/UnEscapedBackslashInString/UnEscapedBackslashInString.h"
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
    const TableTypes::Column column = arguments.size();
    IntegerParser::ParseResult result;
    try {
        result = IntegerParser::parse(command);
    } catch(const IntegerParser::SingleSign& error) {
        return showMessage(new SingleSign{column, error.getSign()});
    } catch(const IntegerParser::InvalidInteger& error) {
        return showMessage(new InvalidInteger{column, error});
    } catch(const IntegerParser::MinLimit& error) {
        return showMessage(new IntegerOutOfRange{column, error.getToken()});
    } catch(const IntegerParser::MaxLimit& error) {
        return showMessage(new IntegerOutOfRange{column, error.getToken()});
    } catch(const Exception&) {
        setState(InsertState::MissingValue);
        return this;
    }
    Action::command = result.getRest();
    arguments.push(result.getParsed());
    return this;
}

Action* Insert::parseFractionalNumber() {
    const TableTypes::Column column = arguments.size();
    FractionalNumberParser::ParseResult result;
    try {
        result = FractionalNumberParser::parse(command);
    } catch(const FractionalNumberParser::SingleFloatingPoint& error) {
        return showMessage(new SingleFloatingPoint{column});
    } catch(const FractionalNumberParser::FractionalNumberHasNoIntegerPart& error) {
        return showMessage(new FractionalNumberHasNoIntegerPart{column, error.getToken()});
    } catch(const FractionalNumberParser::FractionalNumberHasNoFractionalPart& error) {
        return showMessage(new FractionalNumberHasNoFractionalPart{column, error.getToken()});
    } catch(const FractionalNumberParser::InvalidFractionalNumber& error) {
        return showMessage(new InvalidFractionalNumber{column, error});
    } catch(const FractionalNumberParser::DigitsCountLimit& error) {
        return showMessage(new FractionalNumberDigitsLimit(column, error.getToken()));
    } catch(const Exception&) {
        setState(InsertState::MissingValue);
        return this;
    }
    Action::command = result.getRest();
    arguments.push(result.getParsed());
    return this;
}

Action* Insert::parseString() {
    const TableTypes::Column column = arguments.size();
    StringParser::ParseResult result;
    try {
        result = StringParser::parse(command);
    } catch(const StringParser::MissingQuotesInTheBeginning& error) {
        return showMessage(new MissingDoubleQuotesInTheBeginning(column, error.getToken()));
    } catch(const StringParser::MissingQuotesInTheEnd& error) {
        return showMessage(new MissingDoubleQuotesInTheEnd(column, error.getToken()));
    } catch(const StringParser::UnEscapedBackslash& error) {
        return showMessage(new UnEscapedBackslashInString(column, error));
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