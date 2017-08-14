#pragma once

#include "../../../String/String.h"

class ListModel {
public:
    virtual const String& title() const noexcept = 0;

    virtual const String& item(size_t index) const noexcept = 0;

    virtual size_t itemsCount() const noexcept = 0;

    virtual ~ListModel() noexcept = default;
};