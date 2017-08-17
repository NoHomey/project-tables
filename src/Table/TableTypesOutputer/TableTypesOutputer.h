#pragma once

#include "../../CharOutputStream/CharOutputStream.h"
#include "../../FileIO/Writer/Writer.h"
#include "../../SharedPtr/SharedPtr.htd"
#include "../../String/String.h"
#include "../TableTypes/TableTypes.h"
#include "../ColumnMetaData/ColumnMetaData.h"
#include "../TableTypes/StringifiedIntegerLimits.h"

class TableTypesOutputer {
public:
    TableTypesOutputer() = delete;

public:
    /*static void output(Writer& writer, const SharedPtr& sharedPtr, ColumnMetaData::ColumnType);

    static void output(CharOutputStream& outputStream, const SharedPtr& sharedPtr, ColumnMetaData::ColumnType);

    static size_t outputCount(const SharedPtr& sharedPtr);*/

    static void output(CharOutputStream& outputStream, const String& string);

    static void output(CharOutputStream& outputStream, TableTypes::Integer integer);

private:
    static void outputInteger(CharOutputStream& outputStream, TableTypes::Integer integer);

private:
    static char integerBuffer[StringifiedIntegerLimits::DigitsCountOfMin];
};