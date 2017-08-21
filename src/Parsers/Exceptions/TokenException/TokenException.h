#pragma once

#include <cstddef>
#include "../Exception.h"
#include "../../../String/ConstString/ConstString.h"

class TokenException: public Exception {
public:
    TokenException(ConstString& token) noexcept;

    ConstString& getToken() const noexcept;

protected:
    ConstString token;
};