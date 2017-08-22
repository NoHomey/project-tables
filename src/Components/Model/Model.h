#pragma once

class Model {
public:
    static void deleteIfDeletable(const Model* model) noexcept;

public:
    Model(bool deletable) noexcept;

    virtual ~Model() noexcept = default;

    Model(const Model& other) = delete;

    Model(Model&& other) = delete;

    Model& operator=(const Model& other) = delete;

    Model& operator=(Model&& other) = delete;

public:
    bool isDeletable() const noexcept;

private:
    const bool deletable;
};