#pragma once

#include "../String/FixedSizeString/FixedSizeString.h"

namespace TableTypes {
    using Dimention = unsigned int;
    
    using Column = Dimention;

    using Row = Dimention;

    using Integer = long;

    using NaturalNumber = size_t;

    using FractionalNumber = double;

    using String = FixedSizeString;
}