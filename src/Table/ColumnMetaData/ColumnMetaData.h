#pragma once

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

    ColumnType getType() const noexcept;

private:
    ColumnType type;
};