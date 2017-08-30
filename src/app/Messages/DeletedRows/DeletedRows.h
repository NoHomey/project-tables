#pragma once

#include "../RowsQueryResult/RowsQueryResult.h"

class DeletedRows: public RowsQueryResult {
public:
    DeletedRows(TableTypes::Row rowsDeleted) noexcept;

    DeletedRows(const DeletedRows& other) = delete;

    DeletedRows(DeletedRows&& other) = delete;

    DeletedRows& operator=(const DeletedRows& other) = delete;

    DeletedRows& operator=(DeletedRows&& other) = delete;

private:
    static ConstString textAction;
};