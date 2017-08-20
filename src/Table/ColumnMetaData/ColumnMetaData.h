#pragma once

#include "../../String/ConstString/ConstString.h"

namespace ColumnMetaDataStrings {
    ConstString Integer{"Integer"};
    
    ConstString FractionalNumber{"FractionalNumber"};
    
    ConstString String{"String"};

    ConstString Unknown{"Unknown"};
}

class ColumnMetaData {
public:
    enum ColumnType {Integer, FractionalNumber, String, Unknown};

public:
    ColumnMetaData() noexcept;

    ColumnMetaData(ColumnType type) noexcept;

public:
    bool isInteger() const noexcept;

    bool isFractionalNumber() const noexcept;

    bool isString() const noexcept;

    bool isUnknown() const noexcept;

    ColumnType getType() const noexcept;

private:
    ColumnType type;
};