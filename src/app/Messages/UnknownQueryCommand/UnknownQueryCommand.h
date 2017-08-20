#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class UnknownQueryCommand: public InfoModel {
public:
    static UnknownQueryCommand* inject(const String& command);

public:
    void output(CharOutputStream& outputStream) const final;

    void releaseResources() noexcept final;

private:
    UnknownQueryCommand() noexcept = default;

    UnknownQueryCommand(const UnknownQueryCommand& other) = delete;

    UnknownQueryCommand(UnknownQueryCommand&& other) = delete;

    UnknownQueryCommand& operator=(const UnknownQueryCommand& other) = delete;

    UnknownQueryCommand& operator=(UnknownQueryCommand&& other) = delete;

private:
    static UnknownQueryCommand instance;

    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString unknownCommand;
};