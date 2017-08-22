#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

template<typename TableNameType>
class MessageContainingTableName: public InfoModel {
protected:
    MessageContainingTableName(const String& tableName, size_t textLength);

    virtual ~MessageContainingTableName() noexcept = default;

    MessageContainingTableName(const MessageContainingTableName& other) = delete;

    MessageContainingTableName(MessageContainingTableName&& other) = delete;

    MessageContainingTableName& operator=(const MessageContainingTableName& other) = delete;

    MessageContainingTableName& operator=(MessageContainingTableName&& other) = delete;

protected:
    void outputTableName(CharOutputStream& outputStream) const;

protected:
    TableNameType tableName;
};