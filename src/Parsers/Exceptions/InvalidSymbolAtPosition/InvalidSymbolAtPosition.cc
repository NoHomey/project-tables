#include "InvalidSymbolAtPosition.h"

InvalidSymbolAtPosition::InvalidSymbolAtPosition(size_t position, char symbol) noexcept
: position{position}, symbol{symbol} {}

size_t InvalidSymbolAtPosition::getPosition() const noexcept {
    return position;
}

char InvalidSymbolAtPosition::getSymbol() const noexcept {
    return symbol;
}