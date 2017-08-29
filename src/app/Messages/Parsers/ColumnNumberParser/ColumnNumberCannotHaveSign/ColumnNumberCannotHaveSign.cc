#include "ColumnNumberCannotHaveSign.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"

ConstString ColumnNumberCannotHaveSign::textBeginning{"Parse Error: found sign: '"};

ConstString ColumnNumberCannotHaveSign::textInValue{"' in the value: '"};

ConstString ColumnNumberCannotHaveSign::textEnding{"' for Column number. Column numbers can not have sign."};

const size_t ColumnNumberCannotHaveSign::ownTextLength = textBeginning.length() +
                                    textInValue.length() + textEnding.length() + 1;

ColumnNumberCannotHaveSign::ColumnNumberCannotHaveSign(ConstString& invalid) noexcept
: InfoModel{ownTextLength + invalid.length(), false},
invalid{FixedSizeString::fromString(invalid)} { }

void ColumnNumberCannotHaveSign::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    outputStream << invalid[0];
    TypesOutputer::output(outputStream, textInValue);
    TypesOutputer::output(outputStream, invalid);
    TypesOutputer::output(outputStream, textEnding);
}