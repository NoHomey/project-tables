#include "Argument.h"
#include <utility>
#include <new>

Argument::Argument() noexcept
: type{ArgumentType::Column} {
    new (&column) TableTypes::Column{0};
}

void Argument::destruct() noexcept {
    typedef TableTypes::Column Column;
    typedef TableTypes::Integer Integer;
    typedef TableTypes::FractionalNumber FractionalNumber;
    typedef TableTypes::String String;

    switch(type) {
        case ArgumentType::Column:
            column.~Column();
            break;
        case ArgumentType::Integer:
            integer.~Integer();
            break;
        case ArgumentType::FractionalNumber:
            fractionalNumber.~FractionalNumber();
            break;
        case ArgumentType::String:
            string.~String();
            break;
        case ArgumentType::TemporaryString:
            temporaryString.~ImmutableString();
            break;
    }
}

Argument::~Argument() noexcept {
    destruct();
}

Argument::Argument(TableTypes::Column value) noexcept
: type{ArgumentType::Column} {
    new (&column) TableTypes::Column{value};
}

Argument::Argument(TableTypes::Integer value) noexcept
: type{ArgumentType::Integer} {
    new (&integer) TableTypes::Integer{value};
}

Argument::Argument(TableTypes::FractionalNumber value) noexcept
: type{ArgumentType::FractionalNumber} {
    new (&fractionalNumber) TableTypes::FractionalNumber{value};
}

Argument::Argument(TableTypes::String&& value) noexcept
: type{ArgumentType::String} {
    new (&string) TableTypes::String{std::move(value)};
}

Argument::Argument(ConstString& value) noexcept
: type{ArgumentType::TemporaryString} {
    new (&temporaryString) ImmutableString{value};
}

void Argument::create(Argument&& other) noexcept {
    switch(other.type) {
        case ArgumentType::Column:
            new (&column) TableTypes::Column{other.column};
            break;
        case ArgumentType::Integer:
            new (&integer) TableTypes::Integer{other.integer};
            break;
        case ArgumentType::FractionalNumber:
            new (&fractionalNumber) TableTypes::FractionalNumber{other.fractionalNumber};
            break;
        case ArgumentType::String:
            new (&string) TableTypes::String{std::move(other.string)};
            break;
        case ArgumentType::TemporaryString:
            new (&temporaryString) ImmutableString{other.temporaryString};
            break;
    }
}

Argument::Argument(Argument&& other) noexcept
: type{other.type} {
    create(std::move(other));
}

Argument& Argument::operator=(Argument&& other) noexcept {
    if(this != &other) {
        destruct();
        create(std::move(other));
        type = other.type;
    }
    return *this;
}

Argument::ArgumentType Argument::getType() const noexcept {
    return type;
}

bool Argument::isColumn() const noexcept {
    return type == ArgumentType::Column;
}
    
bool Argument::isInteger() const noexcept {
    return type == ArgumentType::Integer;
}
    
bool Argument::isFractionalNumber() const noexcept {
    return type == ArgumentType::FractionalNumber;
}
    
bool Argument::isString() const noexcept {
    return type == ArgumentType::String;
}
    
bool Argument::isTemporaryString() const noexcept {
    return type == ArgumentType::TemporaryString;
}

TableTypes::Column Argument::asColumn() const noexcept {
    return column;
}

TableTypes::Integer Argument::asInteger() const noexcept {
    return integer;
}

TableTypes::FractionalNumber Argument::asFractionalNumber() const noexcept {
    return fractionalNumber;
}

const TableTypes::String& Argument::asString() const noexcept {
    return string;
}

TableTypes::String Argument::moveString() noexcept {
    TableTypes::String tmp = std::move(string);
    string = {};
    return tmp;
}

ConstString& Argument::asTemporaryString() const noexcept {
    return temporaryString;
}

void Argument::null() noexcept {
    if(isTemporaryString()) {
        temporaryString = {};
    } else if(isString() && (string.length() != 0)) {
        string = {};
    }
}