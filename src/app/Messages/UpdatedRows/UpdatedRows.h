#pragma once

#include "../RowsQueryResult/RowsQueryResult.h"

class UpdatedRows: public RowsQueryResult {
public:
    UpdatedRows(TableTypes::Row rowsUpdated) noexcept;

    UpdatedRows(const UpdatedRows& other) = delete;

    UpdatedRows(UpdatedRows&& other) = delete;

    UpdatedRows& operator=(const UpdatedRows& other) = delete;

    UpdatedRows& operator=(UpdatedRows&& other) = delete;

private:
    static ConstString textAction;
};