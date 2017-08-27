#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../Table/Table.h"

class WrongNumberOfColumns: public InfoModel {
public:
    WrongNumberOfColumns(const Table* table, TableTypes::Column valuesCount);

    WrongNumberOfColumns(const WrongNumberOfColumns& other) = delete;

    WrongNumberOfColumns(WrongNumberOfColumns&& other) = delete;

    WrongNumberOfColumns& operator=(const WrongNumberOfColumns& other) = delete;

    WrongNumberOfColumns& operator=(WrongNumberOfColumns&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(const Table* table, TableTypes::Column valuesCount) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textHas;
    
    static ConstString textColumnsValues;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString tableName;

    TableTypes::Column valuesCount;

    TableTypes::Column columnsCount;
};