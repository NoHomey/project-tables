#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class UnknownQueryCommand: public InfoModel {
public:
    UnknownQueryCommand(const String& command);

    UnknownQueryCommand(const UnknownQueryCommand& other) = delete;

    UnknownQueryCommand(UnknownQueryCommand&& other) = delete;

    UnknownQueryCommand& operator=(const UnknownQueryCommand& other) = delete;

    UnknownQueryCommand& operator=(UnknownQueryCommand&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString unknownCommand;
};