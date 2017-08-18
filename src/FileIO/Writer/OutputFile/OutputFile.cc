#include "OutputFile.h"
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

OutputFile::OutputFile(const char* file)
: fd{-1} {
    errno = 0;
    fd = TEMP_FAILURE_RETRY(::open(file, WRITE_FLAGS, ALL_READ_WRITE));
    if(fd == -1) {
        throw errno;
    }
}

OutputFile::~OutputFile() noexcept {
    if(fd >= 0) {
        TEMP_FAILURE_RETRY(::close(fd));
    }
}

void OutputFile::invalidateFd() noexcept {
    fd = -1;
}

OutputFile::OutputFile(OutputFile&& other) noexcept
: fd{other.fd} {
    other.invalidateFd();
}

OutputFile& OutputFile::operator=(OutputFile&& other) noexcept {
    if(this != &other) {
        fd = other.fd;
        other.invalidateFd();
    }
    return *this;
}

size_t OutputFile::write(const char* data, size_t count) {
    if((fd < 0) || (count == 0)) {
        return 0;
    }
    errno = 0;
    const ssize_t writeCount = TEMP_FAILURE_RETRY(::write(fd, data, count));
    if(writeCount == -1) {
        /*switch(errno) {
            case EDQUOT: break;
            case EFBIG: break;
            case EINVAL: break;
            case EIO: break;
            case ENOSPC: break;
            default: throw errno;
        }*/
        throw errno;
    }
    return writeCount > 0 ? writeCount : write(data, count);
}