#include "TypesOutputer.h"
#include "../Table/TableTypes/Integer.h"
#include "../Table/TableTypes/StringifiedIntegerLimits.h"
#include "../String/ConstString/ConstString.h"
#include "../dependencies/fpconv/fpconv.h"
#include "../NullText.h"

char TypesOutputer::integerBuffer[StringifiedIntegerLimits::DigitsCountOfMin];

char TypesOutputer::fpconvBuffer[24];

void TypesOutputer::output(CharOutputStream& outputStream, const String& string) {
    const size_t length = string.length();
    for(size_t index = 0; index < length; ++index) {
        outputStream << string[index];
    }
}

TypesOutputer::NumberLength TypesOutputer::outputCount(TableTypes::Integer integer) noexcept {
    switch(integer) {
        case 0: return 1;
        case Integer::Max: return StringifiedIntegerLimits::Max.length();
        case Integer::Min: return StringifiedIntegerLimits::Min.length();
        default: return outputCountOfInteger(integer);
    }
}

TypesOutputer::NumberLength TypesOutputer::outputCount(TableTypes::Column column) noexcept {
    return outputCount(static_cast<TableTypes::Integer>(column));
}

TypesOutputer::NumberLength TypesOutputer::outputCount(size_t size) noexcept {
    return outputCount(static_cast<TableTypes::Integer>(size));
}

TypesOutputer::NumberLength TypesOutputer::outputCountOfInteger(TableTypes::Integer integer) noexcept {
    const bool isNegative = integer < 0;
    TableTypes::Integer unsignedInteger = isNegative ? -integer : integer;
    unsigned int counter = 0;
    while(unsignedInteger != 0) {
        unsignedInteger /= 10;
        ++counter;
    }
    return counter + isNegative;
}

TypesOutputer::NumberLength TypesOutputer::outputCount(TableTypes::FractionalNumber fractionalNumber) noexcept {
    return fpconv_dtoa(fractionalNumber, fpconvBuffer);
}

void TypesOutputer::output(CharOutputStream& outputStream, TableTypes::Integer integer) {
    switch(integer) {
        case 0:
            outputStream << '0';
            break;
        case Integer::Max: return output(outputStream, StringifiedIntegerLimits::Max);
        case Integer::Min: return output(outputStream, StringifiedIntegerLimits::Min);
        default: return outputInteger(outputStream, integer);
    }
}

void TypesOutputer::output(CharOutputStream& outputStream, TableTypes::Column column) {
    output(outputStream, static_cast<TableTypes::Integer>(column));
}

void TypesOutputer::output(CharOutputStream& outputStream, size_t size) {
    output(outputStream, static_cast<TableTypes::Integer>(size));
}

void TypesOutputer::outputInteger(CharOutputStream& outputStream, TableTypes::Integer integer) {
    TableTypes::Integer unsignedInteger = integer > 0 ? integer : -integer;
    unsigned int index = 0;
    while(unsignedInteger != 0) {
        integerBuffer[index] = (unsignedInteger % 10) + '0';
        unsignedInteger /= 10;
        ++index;
    }
    if(integer < 0) {
        outputStream << '-';
    }
    for(unsigned int revIndex = index; revIndex > 0; --revIndex) {
        outputStream << integerBuffer[revIndex - 1];
    }
}

void TypesOutputer::output(CharOutputStream& outputStream, TableTypes::FractionalNumber fractionalNumber) {
    const size_t count = fpconv_dtoa(fractionalNumber, fpconvBuffer);
    output(outputStream, ConstString{fpconvBuffer, count});
}

void TypesOutputer::output(Writer& writer, const TableTypes::String& string) {
    const size_t length = string.length();
    char symbol;
    writer << '"';
    for(size_t index = 0; index < length; ++index) {
        symbol = string[index];
        switch(symbol) {
            case '"':
            case '\\':
                writer << '\\';
            default: 
                writer << symbol;
        }
    }
    writer << '"';
}

template<typename Output>
void TypesOutputer::outputTableData(Output& outputStream, const SharedPtr& sharedPtr, ColumnMetaData::ColumnType columnType) {
    if(sharedPtr.isNullPtr()) {
        return output(outputStream, NullText);
    }
    switch(columnType) {
        case ColumnMetaData::Integer: return output(outputStream, sharedPtr.getCopy<TableTypes::Integer>());
        case ColumnMetaData::FractionalNumber: return output(outputStream, sharedPtr.getCopy<TableTypes::FractionalNumber>());
        case ColumnMetaData::String: return output(outputStream, sharedPtr.getConstRef<TableTypes::String>());
        default: return output(outputStream, NullText);
    }
}

void TypesOutputer::output(Writer& writer, const SharedPtr& sharedPtr, ColumnMetaData::ColumnType columnType) {
    outputTableData(writer, sharedPtr, columnType);
}

void TypesOutputer::output(CharOutputStream& outputStream, const SharedPtr& sharedPtr, ColumnMetaData::ColumnType columnType) {
    outputTableData(outputStream, sharedPtr, columnType);
}