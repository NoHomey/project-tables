#pragma once

#include "../../../../Table/TableTypes/TableTypes.h"
#include "../../../../String/ConstString/ConstString.h"

class Argument {
public:
    enum class ArgumentType {Null, Column, Integer, FractionalNumber, String, TemporaryString};

private:
    union {
        void* nullPtr;

        TableTypes::Column column;

        TableTypes::Integer integer;

        TableTypes::FractionalNumber fractionalNumber;

        TableTypes::String string;

        ImmutableString temporaryString;
    };

public:
    Argument() noexcept;

    ~Argument() noexcept;

    Argument(std::nullptr_t) noexcept;

    Argument(TableTypes::Column value) noexcept;

    Argument(TableTypes::Integer value) noexcept;

    Argument(TableTypes::FractionalNumber value) noexcept;

    Argument(TableTypes::String&& value) noexcept;

    Argument(ConstString& value) noexcept;

    Argument(const Argument& other) = delete;

    Argument(Argument&& other) noexcept;

    Argument& operator=(const Argument& other) = delete;

    Argument& operator=(Argument&& other) noexcept;
   
public:
    ArgumentType getType() const noexcept;

    bool isNull() const noexcept;

    bool isColumn() const noexcept;
    
    bool isInteger() const noexcept;
    
    bool isFractionalNumber() const noexcept;
    
    bool isString() const noexcept;
    
    bool isTemporaryString() const noexcept;

public:
    TableTypes::Column asColumn() const noexcept;

    TableTypes::Integer asInteger() const noexcept;

    TableTypes::FractionalNumber asFractionalNumber() const noexcept;

    const TableTypes::String& asString() const noexcept;

    TableTypes::String moveString() noexcept;

    ConstString& asTemporaryString() const noexcept;

public:
    void null() noexcept;

private:
    void destruct() noexcept;

    void create(Argument&& other) noexcept;

private:
    ArgumentType type;
};