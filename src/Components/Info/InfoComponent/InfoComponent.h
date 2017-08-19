#pragma once

#include "../../Component.h"
#include "../../../String/String.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class InfoComponent: public Component {
public:
    static InfoComponent* inject(const String& string);

public:
    void render() final;

    void onComponentUnmount() final;

private:
    InfoComponent() noexcept = default;

private:
    static InfoComponent component;

private:
    FixedSizeString text;
};