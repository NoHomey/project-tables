#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"

class MissingArgument: public InfoModel {
public:
    MissingArgument(ConstString& argumentDescription, ConstString& command, unsigned int argument) noexcept;

    virtual ~MissingArgument() noexcept = default;

    MissingArgument(const MissingArgument& other) = delete;

    MissingArgument(MissingArgument&& other) = delete;

    MissingArgument& operator=(const MissingArgument& other) = delete;

    MissingArgument& operator=(MissingArgument&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(ConstString& argumentDescription, ConstString& command, unsigned int argument) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textExpects;

    static ConstString textAs;

    static ConstString textEnding;

    static const size_t ownTextLength;

    static const unsigned char mappedArgumentIndexNamesCount = 6;
    
    static ConstString mappedArgumentIndexNames[mappedArgumentIndexNamesCount];

private:
    ConstString argumentDescription;

    ConstString commandName;

    ConstString argument;
};