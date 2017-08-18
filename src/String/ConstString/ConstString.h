#pragma once

#include "../String.h"

class ImmutableString: public String {
public:
    ImmutableString() noexcept = default;

    ImmutableString(const char* string, size_t length) noexcept;
    
    ImmutableString(const char* string) noexcept;
    
    ImmutableString(const ImmutableString& other) noexcept;
    
    ImmutableString& operator=(const ImmutableString& other) noexcept;
    
    ImmutableString(ImmutableString&& other) noexcept = default;
    
    ImmutableString& operator=(ImmutableString&& other) noexcept = default;

    ImmutableString(const ImmutableString& other, size_t offset) noexcept;

    ImmutableString(const ImmutableString& other, size_t offset, size_t length) noexcept;
};

using ConstString = const ImmutableString;