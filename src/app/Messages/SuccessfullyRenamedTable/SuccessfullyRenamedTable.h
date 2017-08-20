#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class SuccessfullyRenamedTable: public MessageContainingTableName<ImmutableString> {
public:
    static SuccessfullyRenamedTable* inject(FixedSizeString&& oldTableName, const FixedSizeString& newTableName) noexcept;

public:
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
};