#include "String.h"

char String::operator[](size_t index) const noexcept {
    return index < stringLength ? string[index] : '\0';
}

size_t String::length() const noexcept {
    return stringLength;
}

const char* String::cString() const noexcept {
    return string;
}

bool String::compareStrings(const String& other, const bool onEqual, bool (*onDiff)(char a, char b)) const noexcept {
    if(this == &other) {
        return onEqual;
    }
    size_t index = 0;
    char thisChar;
    char otherChar;
    while(true) {
        thisChar = operator[](index);
        otherChar = other[index];
        if(thisChar != otherChar) {    
            return onDiff(thisChar, otherChar);
        } else if(thisChar == '\0') {
            return onEqual;
        }
        ++index;
    }
}

bool String::constFalse(char, char) noexcept {
    return false;
}

bool String::lessThanOperator(char a, char b) noexcept {
    return a < b;
}

bool String::operator==(const String& other) const noexcept {
    return compareStrings(other, true, constFalse);
}

bool String::operator!=(const String& other) const noexcept {
    return !operator==(other);
}

bool String::operator<(const String& other) const noexcept {
    return compareStrings(other, false, lessThanOperator);
}

bool String::operator>(const String& other) const noexcept {
    return other < *this;
}

bool String::operator<=(const String& other) const noexcept {
    return !operator>(other);
}

bool String::operator>=(const String& other) const noexcept {
    return !operator<(other);
}

size_t String::calculateLength(const char* string) noexcept {
    size_t length = 0;
    if(string != nullptr) {
        char symbol = string[length];
        while(symbol != '\0') {
            ++length;
            symbol = string[length];
        }
    }
    return length;
}

String::String() noexcept
: stringLength{0}, string{nullptr} { }

String::String(char* string, size_t length) noexcept
: stringLength{length}, string{string} { }

String::String(const char* string, size_t length) noexcept
: stringLength{length}, string{const_cast<char*>(string)} { }

String::String(char* string) noexcept
: String{string, calculateLength(string)} { }

String::String(const char* string) noexcept
: String{string, calculateLength(string)} { }

void String::null() noexcept {
    string = nullptr;
    stringLength = 0;
}

String::String(String&& other) noexcept
: String{other.string, other.stringLength} {
    other.null();
}

String& String::operator=(String&& other) noexcept {
    if(this != &other) {
        string = other.string;
        stringLength = other.stringLength;
        other.null();
    }
    return *this;
}