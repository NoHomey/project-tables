#include "InvalidSymbolAtPosition.h"

InvalidSymbolAtPosition::InvalidSymbolAtPosition(size_t position, char symbol, ConstString& token) noexcept
: position{position}, symbol{symbol}, token{token} {}

size_t InvalidSymbolAtPosition::getPosition() const noexcept {
    return position;
}

char InvalidSymbolAtPosition::getSymbol() const noexcept {
    return symbol;
}

ConstString& InvalidSymbolAtPosition::getToken() const noexcept {
    return token;
}