#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../Table/TableTypes/TableTypes.h"

class RowsQueryResult: public InfoModel {
public:
    RowsQueryResult(ConstString& action, TableTypes::Row rowsCounted) noexcept;

    virtual ~RowsQueryResult() noexcept = default;

    RowsQueryResult(const RowsQueryResult& other) = delete;

    RowsQueryResult(RowsQueryResult&& other) = delete;

    RowsQueryResult& operator=(const RowsQueryResult& other) = delete;

    RowsQueryResult& operator=(RowsQueryResult&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLegth(ConstString& action, TableTypes::Row rowsCounted) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString action;

    TableTypes::Row rowsCounted;
};