#pragma once

#include <cstddef>

class String {
public:
    char operator[](size_t index) const noexcept;

    size_t length() const noexcept;

    const char* cString() const noexcept;

public:
    static bool constFalse(char, char) noexcept;

    static bool lessThanOperator(char a, char b) noexcept;

    bool compareStrings(const String& other, const bool onEqual, bool (*onDiff)(char a, char b)) const noexcept;

    bool operator==(const String& other) const noexcept;
    
    bool operator!=(const String& other) const noexcept;
    
    bool operator<(const String& other) const noexcept;
    
    bool operator>(const String& other) const noexcept;

    bool operator<=(const String& other) const noexcept;
    
    bool operator>=(const String& other) const noexcept;

protected:
    static size_t calculateLength(const char* string) noexcept; 

protected:
    String() noexcept;

    String(char* string, size_t length) noexcept;

    String(const char* string, size_t length) noexcept;

    String(char* string) noexcept;

    String(const char* string) noexcept;

    String(const String& other) = delete;

    String& operator=(const String& other) = delete;

    String(String&& other) noexcept;

    String& operator=(String&& other) noexcept;

protected:
    size_t stringLength;

    char* string;

private:
    void null() noexcept;
};