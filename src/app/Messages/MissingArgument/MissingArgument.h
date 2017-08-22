#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"

class MissingArgument: public InfoModel {
public:
    void output(CharOutputStream& outputStream) const final;

    void releaseResources() noexcept final;

protected:
    void set(ConstString& command, ConstString& argument) noexcept;

protected:
    MissingArgument(ConstString& argumentDescription) noexcept;

private:
    MissingArgument(const MissingArgument& other) = delete;

    MissingArgument(MissingArgument&& other) = delete;

    MissingArgument& operator=(const MissingArgument& other) = delete;

    MissingArgument& operator=(MissingArgument&& other) = delete;

private:
    static ConstString textBeginning;

    static ConstString textExpects;

    static ConstString textAs;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString argumentDescription;

    ImmutableString commandName;

    ImmutableString argument;
};