#pragma once

class PolymorphicModel {
public:
    static void deleteIfDeletable(const PolymorphicModel* PolymorphicModel) noexcept;

public:
    PolymorphicModel(bool deletable) noexcept;

    virtual ~PolymorphicModel() noexcept = default;

    PolymorphicModel(const PolymorphicModel& other) = delete;

    PolymorphicModel(PolymorphicModel&& other) = delete;

    PolymorphicModel& operator=(const PolymorphicModel& other) = delete;

    PolymorphicModel& operator=(PolymorphicModel&& other) = delete;

public:
    bool isDeletable() const noexcept;

private:
    const bool deletable;
};