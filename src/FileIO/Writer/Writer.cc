#include "Writer.h"
#include <sys/stat.h>
#include <utility>

size_t Writer::getEfficientBlockSize() noexcept {
    struct stat stats;
    if(stat("/", &stats) == 0) {
        return stats.st_blksize;
    }
    return 4096;
}

Writer::Writer(OutputFile&& file)
: file{std::move(file)}, blockSize{getEfficientBlockSize()}, charCounter{0}, buffer{new char[blockSize]} { }

Writer::~Writer() noexcept {
    delete[] buffer;
}

CharOutputStream& Writer::operator<<(char symbol) {
    buffer[charCounter] = symbol;
    ++charCounter;
    if(charCounter == blockSize) {
        write();
    }
    return *this;
}

void Writer::write() {
    if(charCounter > 0) {
        const size_t written = file.write(buffer, charCounter);
        const size_t difference = charCounter - written;
        for(size_t index = 0; index < difference; ++index) {
            buffer[index] = buffer[written + index];
        }
        charCounter -= written;
    }
}

void Writer::endFile() {
    write();
}