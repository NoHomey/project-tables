#pragma once

#include <cstddef>
#include "../TokenException/TokenException.h"

class InvalidSymbolAtPosition: public TokenException {
public:
    InvalidSymbolAtPosition(size_t position, char symbol, ConstString& token) noexcept;

    size_t getPosition() const noexcept;

    char getSymbol() const noexcept;

protected:
    const size_t position;

    const char symbol;
};