#include "ColumnNumberCannotBe.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString ColumnNumberCannotBe::textBeginning{"Parse Error: Got '"};

ConstString ColumnNumberCannotBe::textCannotBe{"' for Column number. Column number can not be '"};

ConstString ColumnNumberCannotBe::textEnding{"'."};

const size_t ColumnNumberCannotBe::ownTextLength = textBeginning.length() + textCannotBe.length() + textEnding.length();

ColumnNumberCannotBe::ColumnNumberCannotBe(ConstString& invalidToken) noexcept
: InfoModel{ownTextLength + 2 * invalidToken.length(), false}, invalidToken{invalidToken} { }

void ColumnNumberCannotBe::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, invalidToken);
    TypesOutputer::output(outputStream, textCannotBe);
    TypesOutputer::output(outputStream, invalidToken);
    TypesOutputer::output(outputStream, textEnding);
}