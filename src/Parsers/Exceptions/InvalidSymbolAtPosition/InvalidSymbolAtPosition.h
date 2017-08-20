#pragma once

#include <cstddef>
#include "../Exception.h"
#include "../../../String/ConstString/ConstString.h"

class InvalidSymbolAtPosition: public Exception {
public:
    InvalidSymbolAtPosition(size_t position, char symbol, ConstString& token) noexcept;

    size_t getPosition() const noexcept;

    char getSymbol() const noexcept;

    ConstString& getToken() const noexcept;

protected:
    const size_t position;

    const char symbol;

    ConstString token;
};