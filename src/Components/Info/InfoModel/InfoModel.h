#pragma once

#include <cstddef>
#include "../../../CharOutputStream/CharOutputStream.h"

class InfoModel {
public:
    InfoModel() noexcept = default;

    size_t textLength() const noexcept;

    virtual void output(CharOutputStream& outputStream) const = 0;

    virtual void releaseResources() noexcept;

    virtual ~InfoModel() noexcept = default;

protected:
    void setTextLength(size_t textLength) noexcept;

private:
    size_t length = 0;
};