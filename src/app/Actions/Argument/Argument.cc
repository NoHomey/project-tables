#include "Argument.h"
#include <utility>
#include <new>

Argument::Argument() noexcept
: type{Column} {
    new (&column) TableTypes::Column{0};
}

Argument::~Argument() noexcept {
    typedef TableTypes::Column Column;
    typedef TableTypes::Integer Integer;
    typedef TableTypes::FractionalNumber FractionalNumber;;

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

Argument::Argument(TableTypes::Column value) noexcept
: type{Column} {
    new (&column) TableTypes::Column{value};
}

Argument::Argument(TableTypes::Integer value) noexcept
: type{Integer} {
    new (&integer) TableTypes::Integer{value};
}

Argument::Argument(TableTypes::FractionalNumber value) noexcept
: type{FractionalNumber} {
    new (&fractionalNumber) TableTypes::FractionalNumber{value};
}

Argument::Argument(TableTypes::String&& value) noexcept
: type{String} {
    new (&string) TableTypes::String{std::move(value)};
}

Argument::Argument(ImmutableString value) noexcept
: type{TemporaryString} {
    new (&temporaryString) ImmutableString{value};
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

FixedSizeString Argument::asString() noexcept {
    FixedSizeString tmp = std::move(string);
    string = std::move(FixedSizeString{});
    return tmp;
}

ImmutableString Argument::asTemporaryString() const noexcept {
    return temporaryString;
}