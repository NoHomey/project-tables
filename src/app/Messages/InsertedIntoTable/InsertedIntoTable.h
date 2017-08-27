#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class InsertedIntoTable: public MessageContainingTableName<ImmutableString> {
public:
    InsertedIntoTable(const FixedSizeString& tableName);

    InsertedIntoTable(const InsertedIntoTable& other) = delete;

    InsertedIntoTable(InsertedIntoTable&& other) = delete;

    InsertedIntoTable& operator=(const InsertedIntoTable& other) = delete;

    InsertedIntoTable& operator=(InsertedIntoTable&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;
};