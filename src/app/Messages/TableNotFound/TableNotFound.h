#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class TableNotFound: public MessageContainingTableName {
public:
    static TableNotFound* inject(const String& tableName);

public:
    size_t textLength() const noexcept final;

    void output(CharOutputStream& outputStream) const final;

private:
    TableNotFound() noexcept = default;

    TableNotFound(const TableNotFound& other) = delete;

    TableNotFound(TableNotFound&& other) = delete;

    TableNotFound& operator=(const TableNotFound& other) = delete;

    TableNotFound& operator=(TableNotFound&& other) = delete;

private:
    static TableNotFound instance;

    static ConstString textBeginning;

    static ConstString textEnsureExists;

    static ConstString textEnding;

    static const size_t ownTextLength;
};