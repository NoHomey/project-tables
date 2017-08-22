#pragma once

#include "../../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../../String/ConstString/ConstString.h"
#include "../../../../String/FixedSizeString/FixedSizeString.h"

class FileIOMessage: public InfoModel {
protected:
    FileIOMessage(const String& fileName, size_t textLength);

    virtual ~FileIOMessage() noexcept = default;

    FileIOMessage(const FileIOMessage& other) = delete;

    FileIOMessage(FileIOMessage&& other) = delete;

    FileIOMessage& operator=(const FileIOMessage& other) = delete;

    FileIOMessage& operator=(FileIOMessage&& other) = delete;

protected:
    void outputFileName(CharOutputStream& outputStream) const;

protected:
    FixedSizeString fileName;
};