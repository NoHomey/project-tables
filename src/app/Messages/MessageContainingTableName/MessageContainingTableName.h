#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class MessageContainingTableName: public InfoModel {
public:
    void releaseResources() noexcept final;

protected:
    MessageContainingTableName() noexcept = default;

    MessageContainingTableName(const MessageContainingTableName& other) = delete;

    MessageContainingTableName(MessageContainingTableName&& other) = delete;

    MessageContainingTableName& operator=(const MessageContainingTableName& other) = delete;

    MessageContainingTableName& operator=(MessageContainingTableName&& other) = delete;

protected:
    void setTableName(const String& name);

    void outputTableName(CharOutputStream& outputStream) const;

protected:
    FixedSizeString tableName;
};