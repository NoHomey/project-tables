#pragma once

#include "../../Model/Model.h"
#include "../../../String/String.h"

class ListModel: public Model {
public:
    ListModel(bool deletable) noexcept;

    virtual ~ListModel() noexcept = default;

public:
    virtual const String& title() const noexcept = 0;

    virtual const String& item(size_t index) const noexcept = 0;

    virtual size_t itemsCount() const noexcept = 0;
};