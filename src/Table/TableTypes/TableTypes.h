#pragma once

#include "../../String/FixedSizeString/FixedSizeString.h"
#include "Integer.h"
#include "FractionalNumber.h"

namespace TableTypes {
    using Dimention = unsigned int;
    
    using Column = Dimention;

    using Row = Dimention;

    using Integer = Integer::Type;

    using FractionalNumber = FractionalNumber::Type;

    using String = FixedSizeString;
}