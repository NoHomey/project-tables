#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class NoRename: public InfoModel {
public:
    static NoRename* inject(const FixedSizeString& tableName) noexcept;

public:
    size_t textLength() const noexcept final;

    void output(CharOutputStream& outputStream) const final;

    void releaseResources() noexcept final;

private:
    NoRename() noexcept = default;

    NoRename(const NoRename& other) = delete;

    NoRename(NoRename&& other) = delete;

    NoRename& operator=(const NoRename& other) = delete;

    NoRename& operator=(NoRename&& other) = delete;

private:
    static NoRename instance;

    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ImmutableString tableName;
};