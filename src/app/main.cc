#include <iostream>
#include "Table/TableData/TableData.h"

void del(SharedPtr& p) {
    p.release<int>();
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
    data.insert(2);
    data.insert("Test");
    data.insert(2);
    data.insert("Ovi");
    data.insert(9);
    data.insert("Ivo");

    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;

    std::cout << "select 0, 2" << std::endl;
    data.selectRowsMatching(0, 2).forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    std::cout << "select 0, 9" << std::endl;
    data.selectRowsMatching(0, 9).forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    std::cout << "select 1, Ivo" << std::endl;
    data.selectRowsMatching(1, "Ivo").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    data.addColumn();

    std::cout << "select 2, null" << std::endl;
    data.selectRowsMatching(2, nullptr).forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;

    return 0;
}