#pragma once

class ColumnMetaData {
public:
    enum ColumnType {Integer, String, Unknown};

public:
    ColumnMetaData() noexcept;

    ColumnMetaData(ColumnType type) noexcept;

public:
    bool isInteger() const noexcept;

    bool isString() const noexcept;

    ColumnType getType() const noexcept;

private:
    ColumnType type;
};