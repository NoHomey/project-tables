#pragma once

#include <cstddef>
#include "../../../CharOutputStream/CharOutputStream.h"

class InfoModel {
public:
    virtual size_t textLength() const noexcept = 0;

    virtual void output(CharOutputStream& outputStream) const = 0;

    virtual ~InfoModel() noexcept = default;
};