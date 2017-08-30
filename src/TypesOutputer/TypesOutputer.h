#pragma once

#include "../CharOutputStream/CharOutputStream.h"
#include "../FileIO/Writer/Writer.h"
#include "../SharedPtr/SharedPtr.htd"
#include "../String/String.h"
#include "../Table/TableTypes/TableTypes.h"
#include "../Table/ColumnMetaData/ColumnMetaData.h"
#include "../Table/TableTypes/StringifiedIntegerLimits.h"

class TypesOutputer {
public:
    using NumberLength = unsigned char;

public:
    TypesOutputer() = delete;

public:
    static void output(Writer& writer, const SharedPtr& sharedPtr, ColumnMetaData::ColumnType columnType);

    static void output(CharOutputStream& outputStream, const SharedPtr& sharedPtr, ColumnMetaData::ColumnType columnType);

    static void output(CharOutputStream& outputStream, const String& string);

    static void output(CharOutputStream& outputStream, TableTypes::Integer integer);

    static void output(CharOutputStream& outputStream, TableTypes::Column column);

    static void output(CharOutputStream& outputStream, size_t size);

    static void output(CharOutputStream& outputStream, TableTypes::FractionalNumber fractionalNumber);

    static void output(Writer& writer, const TableTypes::String& string);

    static NumberLength outputCount(TableTypes::Integer integer) noexcept;

    static NumberLength outputCount(TableTypes::Column column) noexcept;

    static NumberLength outputCount(size_t size) noexcept;

    static NumberLength outputCount(TableTypes::FractionalNumber fractionalNumber) noexcept;

    static size_t outputCount(const SharedPtr& sharedPtr, ColumnMetaData::ColumnType columnType);

private:
    template<typename Output>
    static void outputTableData(Output& outputStream, const SharedPtr& sharedPtr, ColumnMetaData::ColumnType columnType);

private:
    static void outputInteger(CharOutputStream& outputStream, TableTypes::Integer integer);

    static NumberLength outputCountOfInteger(TableTypes::Integer integer) noexcept;

private:
    static char integerBuffer[StringifiedIntegerLimits::DigitsCountOfMin];

    static char fpconvBuffer[24];
};