#pragma once

#include <cstddef>

#define ALL_READ_WRITE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

#define WRITE_FLAGS (O_CREAT | O_DSYNC | O_SYNC | O_WRONLY | O_TRUNC) 
 
class OutputFile {
public:
    OutputFile(const char* file);

    ~OutputFile() noexcept;

    OutputFile(const OutputFile& other) = delete;

    OutputFile(OutputFile&& other) noexcept;

    OutputFile& operator=(const OutputFile& other) = delete;
    
    OutputFile& operator=(OutputFile&& other) noexcept;

public:
    size_t write(const char* data, size_t count);

private:
    void invalidateFd() noexcept;

private:
    int fd;
};