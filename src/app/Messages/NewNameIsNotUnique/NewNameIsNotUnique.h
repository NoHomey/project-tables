#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class NewNameIsNotUnique: public MessageContainingTableName<ImmutableString> {
public:
    static NewNameIsNotUnique* inject(const FixedSizeString& tableName, const FixedSizeString& newTableName) noexcept;

public:
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
    ImmutableString newName;
};