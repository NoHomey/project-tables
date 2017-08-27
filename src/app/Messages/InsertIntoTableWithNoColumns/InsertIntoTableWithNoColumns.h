#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class InsertIntoTableWithNoColumns: public MessageContainingTableName<ImmutableString> {
public:
    InsertIntoTableWithNoColumns(const FixedSizeString& tableName) noexcept;

    InsertIntoTableWithNoColumns(const InsertIntoTableWithNoColumns& other) = delete;

    InsertIntoTableWithNoColumns(InsertIntoTableWithNoColumns&& other) = delete;

    InsertIntoTableWithNoColumns& operator=(const InsertIntoTableWithNoColumns& other) = delete;

    InsertIntoTableWithNoColumns& operator=(InsertIntoTableWithNoColumns&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t textLength;
};