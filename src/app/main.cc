#include <iostream>
#include "Table/TableData/TableData.h"

void print(const TableData& data) {
    const TableTypes::Row rows = data.rowsCount();
    const TableTypes::Row cols = data.columnsCount();
    std::cout << "--------------------------" << std::endl;
    for(TableTypes::Row row = 0; row < rows; ++row) {
        std::cout << data(row, 0).getCopy<TableTypes::Integer>() << ' ' << data(row, 1).getConstRef<TableTypes::String>()[0];
        for(size_t i = 2; i < cols; ++i) {
            if(data(row, i).isNullPtr()) {
                std::cout << " NULL";
            } else {
                std::cout << ' ' << data(row, 0).getCopy<TableTypes::Integer>();
            }
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

int main() {
    TableData data;

    data.addColumn();
    data.addColumn();
    data.insert(2);
    data.insert("Ivo");
    data.insert(2);
    data.insert("Ivo");
    data.insert(2);
    data.insert("Ivo");
    data.insert(100);
    data.insert("Test");
    data.insert(22);
    data.insert("Ovi");
    data.insert(22);
    data.insert("Ovi");
    data.insert(9);
    data.insert("Ivo");
    data.insert(9);
    data.insert("Ivo");
    data.insert(100);
    data.insert("Test");
    data.insert(22);
    data.insert("Ovi");
    data.insert(1000);
    data.insert("AAA");
    data.insert(22);
    data.insert("Ovi");
    data.insert(9);
    data.insert("Ivo");
    data.insert(9);
    data.insert("Ivo");

    for(size_t i  = 0; i < 9; ++i) {
        print(data);
        data.addColumn();
        data.updateRows(data.selectAllRows(), i + 2, i * i);
    }

    data.addColumn();
    print(data);

    return 0;
}