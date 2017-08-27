#include "InvalidSymbolAtPosition.h"

InvalidSymbolAtPosition::InvalidSymbolAtPosition(size_t position, char symbol, ConstString& token) noexcept
: TokenException{token}, position{position + 1}, symbol{symbol} { }

size_t InvalidSymbolAtPosition::getPosition() const noexcept {
    return position;
}

char InvalidSymbolAtPosition::getSymbol() const noexcept {
    return symbol;
}