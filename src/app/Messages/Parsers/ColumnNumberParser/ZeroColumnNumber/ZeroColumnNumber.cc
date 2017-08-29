#include "ZeroColumnNumber.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString ZeroColumnNumber::invalidToken{"0"};

ZeroColumnNumber ZeroColumnNumber::instance;

ZeroColumnNumber::ZeroColumnNumber() noexcept
: ColumnNumberCannotBe{invalidToken} { }

ZeroColumnNumber* ZeroColumnNumber::zeroColumnNumber() {
    return &instance;
}