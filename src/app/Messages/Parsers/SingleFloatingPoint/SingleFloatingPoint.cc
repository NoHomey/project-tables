#include "SingleFloatingPoint.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString SingleFloatingPoint::text{"Column type is 'FractionalNumber' and input value is: '.' which is a single floating point and it is treated as incomplete value of type 'FractionNumber'."};

SingleFloatingPoint::SingleFloatingPoint(TableTypes::Column column) noexcept
: ParserMessage{column, text.length()} { }

void SingleFloatingPoint::outputOwnText(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
}