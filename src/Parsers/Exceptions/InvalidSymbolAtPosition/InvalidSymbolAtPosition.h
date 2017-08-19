#pragma once

#include <cstddef>
#include "../Exception.h"

class InvalidSymbolAtPosition: public Exception {
public:
    InvalidSymbolAtPosition(size_t position, char symbol) noexcept;

    size_t getPosition() const noexcept;

    char getSymbol() const noexcept;

protected:
    const size_t position;

    const char symbol;
};