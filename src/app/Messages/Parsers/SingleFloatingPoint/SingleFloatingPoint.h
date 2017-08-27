#pragma once

#include "../ParserMessage/ParserMessage.h"

class SingleFloatingPoint: public ParserMessage {
public:
    SingleFloatingPoint(TableTypes::Column column) noexcept;

    SingleFloatingPoint(const SingleFloatingPoint& other) = delete;

    SingleFloatingPoint(SingleFloatingPoint&& other) = delete;

    SingleFloatingPoint& operator=(const SingleFloatingPoint& other) = delete;

    SingleFloatingPoint& operator=(SingleFloatingPoint&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static ConstString text;
};