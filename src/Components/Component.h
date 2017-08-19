#pragma once

class Component {
public:
    virtual void render() = 0;

    virtual void onComponentUnmount() { };

    virtual ~Component() noexcept = default;
};