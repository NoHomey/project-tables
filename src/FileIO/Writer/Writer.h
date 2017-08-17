#pragma once

#include <cstddef>
#include "../../CharOutputStream/CharOutputStream.h"
#include "OutputFile/OutputFile.h"

class Writer: public CharOutputStream {
public:
    static Writer& obtainWriter(OutputFile&& file) noexcept; 

public:
    Writer(OutputFile&& file);

    ~Writer() noexcept;

    Writer(const Writer& other) = delete;

    Writer(Writer&& other) = delete;
    
    Writer& operator=(const Writer& other) = delete;

    Writer& operator=(Writer&& other) = delete;

public:
    CharOutputStream& operator<<(char symbol) final;

    void endFile();

private:
    static size_t getEfficientBlockSize() noexcept;

private:
    void write();

private:
    OutputFile file;

    size_t blockSize;

    size_t charCounter;

    char* buffer;
};