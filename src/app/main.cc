#include <iostream>
#include "Table/TableData/TableData.h"

void print(const TableData& data) {
    const TableTypes::Row rows = data.rowsCount();
    TableTypes::Row cols = data.columnsCount();
    if(cols == 12) {
        cols = 11;
    }
    std::cout << "------------------------------------" << std::endl;
    for(TableTypes::Row row = 0; row < rows; ++row) {
        std::cout << data(row, 0).getCopy<TableTypes::Integer>() << ' ' << data(row, 1).getConstRef<TableTypes::String>()[0];
        for(size_t i = 2; i < cols; ++i) {
            if(data(row, i).isNullPtr()) {
                std::cout << " NULL";
            } else {
                std::cout << ' ' << data(row, i).getCopy<TableTypes::Integer>();
            }
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}

void printFinal(const TableData& data) {
    const TableTypes::Row rows = data.rowsCount();
    std::cout << "------------------------------------" << std::endl;
    for(TableTypes::Row row = 0; row < rows; ++row) {
        std::cout << data(row, 0).getCopy<TableTypes::Integer>() << ' ' << data(row, 1).getConstRef<TableTypes::String>()[0];
        for(size_t i = 2; i < 11; ++i) {
            std::cout << ' ' << data(row, i).getCopy<TableTypes::Integer>();
        }
        std::cout << ' ' << data(row, 11).getCopy<TableTypes::FractionalNumber>() << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}

TableTypes::Integer integer(int i) {
    return i;
}

int main() {
    TableData data;

    data.addColumn();
    data.addColumn();
    data.insert(integer(2));
    data.insert("Ivo");
    data.insert(integer(2));
    data.insert("Ivo");
    data.insert(integer(2));
    data.insert("Ivo");
    data.insert(integer(100));
    data.insert("Test");
    data.insert(integer(22));
    data.insert("Ovi");
    data.insert(integer(2));
    data.insert("Ovi");
    data.insert(integer(2));
    data.insert("Ivo");
    data.insert(integer(2));
    data.insert("Ivo");
    data.insert(integer(100));
    data.insert("Test");
    data.insert(integer(22));
    data.insert("Ovi");
    data.insert(integer(100));
    data.insert("AAA");
    data.insert(integer(22));
    data.insert("Ovi");
    data.insert(integer(2));
    data.insert("Ivo");
    data.insert(integer(2));
    data.insert("Ivo");

    for(size_t i  = 0; i < 9; ++i) {
        print(data);
        data.addColumn();
        data.updateRows(data.selectAllRows(), i + 2, integer(i * i));
    }

    data.addColumn();
    print(data);
    data.updateRows(data.selectAllRows(), 11, 3.14);
    printFinal(data);

    std::cout << data.selectRowsMatching(11, 3.14).count() << std::endl;

    return 0;
}