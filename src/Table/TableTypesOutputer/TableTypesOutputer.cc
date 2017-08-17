#include "TableTypesOutputer.h"
#include "../TableTypes/Integer.h"
#include "../TableTypes/StringifiedIntegerLimits.h"
#include "../../String/ConstString/ConstString.h"
#include "../../dependencies/fpconv/fpconv.h"

char TableTypesOutputer::integerBuffer[StringifiedIntegerLimits::DigitsCountOfMin];

char TableTypesOutputer::fpconvBuffer[24];

void TableTypesOutputer::output(CharOutputStream& outputStream, const String& string) {
    const size_t length = string.length();
    for(size_t index = 0; index < length; ++index) {
        outputStream << string[index];
    }
}

void TableTypesOutputer::output(CharOutputStream& outputStream, TableTypes::Integer integer) {
    switch(integer) {
        case 0:
            outputStream << '0';
            break;
        case Integer::Max: return output(outputStream, StringifiedIntegerLimits::Max);
        case Integer::Min: return output(outputStream, StringifiedIntegerLimits::Min);
        default: return outputInteger(outputStream, integer);
    }
}

void TableTypesOutputer::outputInteger(CharOutputStream& outputStream, TableTypes::Integer integer) {
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

void TableTypesOutputer::output(CharOutputStream& outputStream, TableTypes::FractionalNumber fractionalNumber) {
    const size_t count = fpconv_dtoa(fractionalNumber, fpconvBuffer);
    output(outputStream, ConstString{fpconvBuffer, count});
}