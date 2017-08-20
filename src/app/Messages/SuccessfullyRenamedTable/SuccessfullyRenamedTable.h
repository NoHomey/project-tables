#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class SuccessfullyRenamedTable: public InfoModel {
public:
    static SuccessfullyRenamedTable* inject(FixedSizeString&& oldTableName, const FixedSizeString& newTableName) noexcept;

public:
    size_t textLength() const noexcept final;

    void output(CharOutputStream& outputStream) const final;

    void releaseResources() noexcept final;

private:
    SuccessfullyRenamedTable() noexcept = default;

    SuccessfullyRenamedTable(const SuccessfullyRenamedTable& other) = delete;

    SuccessfullyRenamedTable(SuccessfullyRenamedTable&& other) = delete;

    SuccessfullyRenamedTable& operator=(const SuccessfullyRenamedTable& other) = delete;

    SuccessfullyRenamedTable& operator=(SuccessfullyRenamedTable&& other) = delete;

private:
    static SuccessfullyRenamedTable instance;

    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString oldName;

    ImmutableString newName;
};