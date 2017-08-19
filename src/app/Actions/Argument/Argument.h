#pragma once

#include "../../../Table/TableTypes/TableTypes.h"
#include "../../../String/ConstString/ConstString.h"

class Argument {
private:
    enum ArgumentType {Column, Integer, FractionalNumber, String, TemporaryString};

    union {
        TableTypes::Column column;

        TableTypes::Integer integer;

        TableTypes::FractionalNumber fractionalNumber;

        TableTypes::String string;

        ImmutableString temporaryString;
    };

public:
    Argument() noexcept;

    ~Argument() noexcept;

    Argument(TableTypes::Column value) noexcept;

    Argument(TableTypes::Integer value) noexcept;

    Argument(TableTypes::FractionalNumber value) noexcept;

    Argument(TableTypes::String&& value) noexcept;

    Argument(ImmutableString value) noexcept;

    TableTypes::Column asColumn() const noexcept;

    TableTypes::Integer asInteger() const noexcept;

    TableTypes::FractionalNumber asFractionalNumber() const noexcept;

    FixedSizeString asString() noexcept;

    ImmutableString asTemporaryString() const noexcept;

private:
    ArgumentType type;
};