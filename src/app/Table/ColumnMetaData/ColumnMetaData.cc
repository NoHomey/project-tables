#include "ColumnMetaData.h"

ColumnMetaData::ColumnMetaData() noexcept
: type{Unknown} { }

ColumnMetaData::ColumnMetaData(ColumnType type) noexcept
: type{type} { }

bool ColumnMetaData::isInteger() const noexcept {
    return type == Integer;
}

bool ColumnMetaData::isString() const noexcept {
    return type == String;
}

ColumnMetaData::ColumnType ColumnMetaData::getType() const noexcept {
    return type;
}