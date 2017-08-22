#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class NewNameIsNotUnique: public MessageContainingTableName<ImmutableString> {
public:
    NewNameIsNotUnique(const FixedSizeString& tableName, const FixedSizeString& newTableName) noexcept;

    NewNameIsNotUnique(const NewNameIsNotUnique& other) = delete;

    NewNameIsNotUnique(NewNameIsNotUnique&& other) = delete;

    NewNameIsNotUnique& operator=(const NewNameIsNotUnique& other) = delete;

    NewNameIsNotUnique& operator=(NewNameIsNotUnique&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textBetweenNames;

    static ConstString textNameIsNotUnique;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString newTableName;
};