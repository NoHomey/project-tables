#pragma once

#include "../../Container/DynamicArray/DynamicArray.htd"

class BasicRenderer {
public:
    static void setup();

    static BasicRenderer& getRenderer() noexcept;

public:
    BasicRenderer(const BasicRenderer&) = delete;

    BasicRenderer& operator=(const BasicRenderer&) = delete;

    BasicRenderer(BasicRenderer&&) = delete;
    
    BasicRenderer& operator=(BasicRenderer&&) = delete;

public:
    void ensureCapacity(size_t capacity);

    BasicRenderer& operator<<(char symbol);

    void clear();

    void render() const;

private:
    static const char* const CLEAR;

    static const size_t CLEAR_LENGTH;

    static BasicRenderer renderer;

private:
    BasicRenderer() noexcept = default;

private:
    DynamicArray<char> buffer;
};