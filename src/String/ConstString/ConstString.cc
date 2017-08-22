#include "ConstString.h"

ImmutableString ImmutableString::fromString(const String& string) noexcept {
    return {string.cString(), string.length()};
}

ImmutableString::ImmutableString(const char* string, size_t length) noexcept
: String{string, length} { }

ImmutableString::ImmutableString(const char* string) noexcept
: String{string} { }

ImmutableString::ImmutableString(const ImmutableString& other) noexcept
: String{other.string, other.stringLength} { }

ImmutableString& ImmutableString::operator=(const ImmutableString& other) noexcept {
    if(this != &other) {
        string = other.string;
        stringLength = other.stringLength;
    }
    return *this;
}

ImmutableString::ImmutableString(const ImmutableString& other, size_t offset) noexcept
: String{(other.string == nullptr) || (other.stringLength <= offset) ? nullptr : other.string + offset,
    other.stringLength <= offset ? 0: other.stringLength - offset} {}

ImmutableString::ImmutableString(const ImmutableString& other, size_t offset, size_t length) noexcept
: String{(other.string == nullptr) || (other.stringLength < (offset + length)) ? nullptr : other.string + offset,
    other.stringLength < (offset + length) ? 0: length} {}