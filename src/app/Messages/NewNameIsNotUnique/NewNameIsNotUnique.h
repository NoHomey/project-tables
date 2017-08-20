#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class NewNameIsNotUnique: public InfoModel {
public:
    static NewNameIsNotUnique* inject(const FixedSizeString& tableName, const FixedSizeString& newTableName) noexcept;

public:
    size_t textLength() const noexcept final;

    void output(CharOutputStream& outputStream) const final;

    void releaseResources() noexcept final;

private:
    NewNameIsNotUnique() noexcept = default;

    NewNameIsNotUnique(const NewNameIsNotUnique& other) = delete;

    NewNameIsNotUnique(NewNameIsNotUnique&& other) = delete;

    NewNameIsNotUnique& operator=(const NewNameIsNotUnique& other) = delete;

    NewNameIsNotUnique& operator=(NewNameIsNotUnique&& other) = delete;

private:
    static NewNameIsNotUnique instance;

    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textNameIsNotUnique;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ImmutableString tableName;

    ImmutableString newName;
};