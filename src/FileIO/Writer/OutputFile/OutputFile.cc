#include "OutputFile.h"
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Exceptions/Exceptions.h"

OutputFile::OutputFile(const char* file)
: fd{-1} {
    errno = 0;
    fd = TEMP_FAILURE_RETRY(::open(file, WRITE_FLAGS, ALL_READ_WRITE));
    if(fd == -1) {
        switch(errno) {
            case EACCES: throw OpenException::PermitionDenied{};
            case EDQUOT: throw OpenException::CannotCreateFile{};
            case EISDIR: throw OpenException::ItIsADirectory{};
            case ENAMETOOLONG: throw OpenException::FileNameIsTooLong{};
            case ENOSPC: throw OpenException::CannotCreateFile{};
            case EOVERFLOW: throw OpenException::FileIsTooLarge{};
            case EPERM: throw OpenException::FileIsSealed{};
            case EROFS: throw OpenException::ReadOnlyFileSystem{};
            default: throw OpenException::CannotOpenFile{};
        }
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
        switch(errno) {
            case EDQUOT: throw WriteException::FileSystemDiskBlocksQuotaExhausted{};
            case EFBIG: throw WriteException::FileIsTooBig{};
            case EINVAL: throw WriteException::CannotWrite{};
            case EIO: throw WriteException::LowLevelException{};
            default: throw WriteException::UnexpectedWriteError{};
        }
    }
    return writeCount > 0 ? writeCount : write(data, count);
}