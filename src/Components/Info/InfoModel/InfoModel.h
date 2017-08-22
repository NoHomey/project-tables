#pragma once

#include <cstddef>
#include "../../../CharOutputStream/CharOutputStream.h"
#include "../../Model/Model.h"

class InfoModel: public Model {
public:
    InfoModel(size_t length, bool deletable) noexcept;

    virtual ~InfoModel() noexcept = default;

public:
    virtual void output(CharOutputStream& outputStream) const = 0;

    size_t textLength() const noexcept;

private:
    const size_t length;
};