#pragma once

class Component {
public:
    virtual void render() = 0;

    virtual ~Component() noexcept = default;
};