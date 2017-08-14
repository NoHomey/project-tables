#pragma once

#include "../String.h"

class ImmutableString: public String {
public:
    ImmutableString(const char* string, size_t length) noexcept;
    
    ImmutableString(const char* string) noexcept;
    
    ImmutableString(const ImmutableString& other) = delete;
    
    ImmutableString& operator=(const ImmutableString& other) = delete;
    
    ImmutableString(ImmutableString&& other) noexcept = default;
    
    ImmutableString& operator=(ImmutableString&& other) noexcept = default;
};

using ConstString = const ImmutableString;