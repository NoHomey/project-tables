#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"

class TableHasNoNothingToBePrinted: public MessageContainingTableName<ImmutableString> {
public:
    TableHasNoNothingToBePrinted(const FixedSizeString& tableName, ConstString& tableHasNo) noexcept;

    virtual ~TableHasNoNothingToBePrinted() noexcept = default;

    TableHasNoNothingToBePrinted(const TableHasNoNothingToBePrinted& other) = delete;

    TableHasNoNothingToBePrinted(TableHasNoNothingToBePrinted&& other) = delete;

    TableHasNoNothingToBePrinted& operator=(const TableHasNoNothingToBePrinted& other) = delete;

    TableHasNoNothingToBePrinted& operator=(TableHasNoNothingToBePrinted&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textHasNo;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString tableHasNo;
};