#include "NullColumnNumber.h"
#include "../../../../../TypesOutputer/TypesOutputer.h"
#include "../../../../../NullText.h"

NullColumnNumber NullColumnNumber::instance;

NullColumnNumber::NullColumnNumber() noexcept
: ColumnNumberCannotBe{NullText} { }

NullColumnNumber* NullColumnNumber::nullColumnNumber() {
    return &instance;
}