#pragma once

#include "../../String/ConstString/ConstString.h"
#include "../../FileIO/Writer/Writer.h"
#include "../Table.h"

class TableOutputerToFile {
public:
    TableOutputerToFile(const Table& table) noexcept;

    TableOutputerToFile(const TableOutputerToFile& other) = delete;

    TableOutputerToFile(TableOutputerToFile&& other) = delete;

    TableOutputerToFile& operator=(const TableOutputerToFile& other) = delete;
    
    TableOutputerToFile& operator=(TableOutputerToFile&& other) = delete;    

public:
    void outputToFile(ConstString& file);

private:
    static const char* ConstStringToCString(ConstString& file);

private:
    void outputTableName(Writer& writer);

    void outputColumnTypes(Writer& writer);

    void outputTableData(Writer& writer);

private:
    const Table& table;
};