#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"

class ColumnsLimitReached: public InfoModel {
public:
    static ColumnsLimitReached* columnsLimitReached();

public:
    void output(CharOutputStream& outputStream) const final;

private:
    ColumnsLimitReached() noexcept;

    ColumnsLimitReached(const ColumnsLimitReached& other) = delete;

    ColumnsLimitReached(ColumnsLimitReached&& other) = delete;

    ColumnsLimitReached& operator=(const ColumnsLimitReached& other) = delete;

    ColumnsLimitReached& operator=(ColumnsLimitReached&& other) = delete;

private:
    static ConstString text;

    static ColumnsLimitReached instance;
};