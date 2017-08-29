#pragma once

#include "../MessageContainingTableName/MessageContainingTableName.h"
#include "../../../Table/Table.h"

class TableHasLessColumns: public MessageContainingTableName<ImmutableString> {
public:
    TableHasLessColumns(const Table& table, TableTypes::Column column);

    TableHasLessColumns(const TableHasLessColumns& other) = delete;

    TableHasLessColumns(TableHasLessColumns&& other) = delete;

    TableHasLessColumns& operator=(const TableHasLessColumns& other) = delete;

    TableHasLessColumns& operator=(TableHasLessColumns&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(const Table& table, TableTypes::Column column) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textHas;
    
    static ConstString textColumnsValues;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    TableTypes::Column column;

    TableTypes::Column columnsCount;
};