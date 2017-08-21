#include "ColumnMetaData.h"

ConstString& ColumnMetaData::columnTypeAsString(ColumnType columnType) noexcept {
    switch(columnType) {
        case ColumnMetaData::Integer: return ColumnMetaDataStrings::Integer;
        case ColumnMetaData::String: return ColumnMetaDataStrings::String;
        case ColumnMetaData::FractionalNumber: return ColumnMetaDataStrings::FractionalNumber;
        default: return ColumnMetaDataStrings::Unknown;
    }
}

ColumnMetaData::ColumnMetaData() noexcept
: type{Unknown} { }

ColumnMetaData::ColumnMetaData(ColumnType type) noexcept
: type{type} { }

bool ColumnMetaData::isInteger() const noexcept {
    return type == Integer;
}

bool ColumnMetaData::isFractionalNumber() const noexcept {
    return type == FractionalNumber;
}

bool ColumnMetaData::isString() const noexcept {
    return type == String;
}

bool ColumnMetaData::isUnknown() const noexcept {
    return type == Unknown;
}

ColumnMetaData::ColumnType ColumnMetaData::getType() const noexcept {
    return type;
}