#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../Table/TableTypes/TableTypes.h"

class CountedRows: public InfoModel {
public:
    CountedRows(TableTypes::Row rowsCounted) noexcept;

    CountedRows(const CountedRows& other) = delete;

    CountedRows(CountedRows&& other) = delete;

    CountedRows& operator=(const CountedRows& other) = delete;

    CountedRows& operator=(CountedRows&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    TableTypes::Row rowsCounted;
};