#include "TokenException.h"

TokenException::TokenException(ConstString& token) noexcept
: token{token} {}

ConstString& TokenException::getToken() const noexcept {
    return token;
}