#include "ConstString.h"

ImmutableString::ImmutableString(const char* string, size_t length) noexcept
: String{string, length} { }

ImmutableString::ImmutableString(const char* string) noexcept
: String{string} { }