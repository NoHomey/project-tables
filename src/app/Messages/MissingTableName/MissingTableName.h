#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"

class MissingTableName: public InfoModel {
public:
    static MissingTableName* inject(ConstString& command, ConstString& argument);

public:
    void output(CharOutputStream& outputStream) const final;

private:
    MissingTableName() noexcept = default;

    MissingTableName(const MissingTableName& other) = delete;

    MissingTableName(MissingTableName&& other) = delete;

    MissingTableName& operator=(const MissingTableName& other) = delete;

    MissingTableName& operator=(MissingTableName&& other) = delete;

protected:
    void releaseResources() noexcept final;

private:
    static MissingTableName instance;

    static ConstString textBeginning;

    static ConstString textExpects;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ImmutableString commandName;

    ImmutableString argument;
};