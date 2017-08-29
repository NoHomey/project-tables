#pragma once

#include "../ColumnNumberCannotBe/ColumnNumberCannotBe.h"

class ZeroColumnNumber: public ColumnNumberCannotBe {
public:
    static ZeroColumnNumber* zeroColumnNumber();

private:
    ZeroColumnNumber() noexcept;

    ZeroColumnNumber(const ZeroColumnNumber& other) = delete;

    ZeroColumnNumber(ZeroColumnNumber&& other) = delete;

    ZeroColumnNumber& operator=(const ZeroColumnNumber& other) = delete;

    ZeroColumnNumber& operator=(ZeroColumnNumber&& other) = delete;

private:
    static ConstString invalidToken;

    static ZeroColumnNumber instance;
};