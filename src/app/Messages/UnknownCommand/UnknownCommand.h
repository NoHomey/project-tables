#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class UnknownCommand: public InfoModel {
public:
    UnknownCommand(const String& command);

    UnknownCommand(const UnknownCommand& other) = delete;

    UnknownCommand(UnknownCommand&& other) = delete;

    UnknownCommand& operator=(const UnknownCommand& other) = delete;

    UnknownCommand& operator=(UnknownCommand&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString unknownCommand;
};