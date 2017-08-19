#include "TypesOutputer.h"
#include "../Table/TableTypes/Integer.h"
#include "../Table/TableTypes/StringifiedIntegerLimits.h"
#include "../String/ConstString/ConstString.h"
#include "../dependencies/fpconv/fpconv.h"

ConstString TypesOutputer::NullText{"NULL"};

char TypesOutputer::integerBuffer[StringifiedIntegerLimits::DigitsCountOfMin];

char TypesOutputer::fpconvBuffer[24];

void TypesOutputer::output(CharOutputStream& outputStream, const String& string) {
    const size_t length = string.length();
    for(size_t index = 0; index < length; ++index) {
        outputStream << string[index];
    }
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

void TypesOutputer::outputInteger(CharOutputStream& outputStream, TableTypes::Integer integer) {
    TableTypes::Integer copy = integer > 0 ? integer : -integer;
    unsigned int index = 0;
    while(copy != 0) {
        integerBuffer[index] = (copy % 10) + '0';
        copy /= 10;
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