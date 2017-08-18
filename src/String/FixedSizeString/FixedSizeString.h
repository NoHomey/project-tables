#pragma once

#include "../String.h"

class FixedSizeString: public String {
public:
    FixedSizeString() noexcept;

    explicit FixedSizeString(const size_t length);

    FixedSizeString(const char* content, size_t length);
    
    FixedSizeString(const char* content);

    ~FixedSizeString() noexcept;
    
    FixedSizeString(const FixedSizeString& other) = delete;
    
    FixedSizeString& operator=(const FixedSizeString& other) = delete;
    
    FixedSizeString(FixedSizeString&& other) noexcept;
    
    FixedSizeString& operator=(FixedSizeString&& other) noexcept;

public:
    FixedSizeString& operator<<(const char symbol) noexcept;
    
    bool isFilled() const noexcept;

private:
    void fill(const char* content) noexcept;

    bool isntFilled() const noexcept;

private:
    size_t filled;
};