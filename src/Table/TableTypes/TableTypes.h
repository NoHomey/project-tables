#pragma once

#include "../../String/FixedSizeString/FixedSizeString.h"
#include "Integer.h"
#include "FractionalNumber.h"

namespace TableTypes {    
    using Column = unsigned int;

    using Row = size_t;

    using Integer = Integer::Type;

    using FractionalNumber = FractionalNumber::Type;

    using String = FixedSizeString;
}