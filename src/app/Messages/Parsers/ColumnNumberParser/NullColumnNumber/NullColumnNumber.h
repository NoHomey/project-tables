#pragma once

#include "../ColumnNumberCannotBe/ColumnNumberCannotBe.h"

class NullColumnNumber: public ColumnNumberCannotBe {
public:
    static NullColumnNumber* nullColumnNumber();

private:
    NullColumnNumber() noexcept;

    NullColumnNumber(const NullColumnNumber& other) = delete;

    NullColumnNumber(NullColumnNumber&& other) = delete;

    NullColumnNumber& operator=(const NullColumnNumber& other) = delete;

    NullColumnNumber& operator=(NullColumnNumber&& other) = delete;

private:
    static NullColumnNumber instance;
};