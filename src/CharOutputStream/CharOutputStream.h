#pragma once

class CharOutputStream {
public:
    virtual CharOutputStream& operator<<(char symbol) = 0;
};