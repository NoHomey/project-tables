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

    std::cout << "update, Test" << std::endl;
    data.updateRows(data.selectRowsMatching(0, 2), 1, "Test"); 
    data.selectRowsMatching(1, "Test").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    std::cout << "udpate, -99" << std::endl;
    data.updateRows(data.selectRowsMatching(0, 9), 2, -99); 
    data.selectRowsMatching(2, -99).forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    std::cout << "udpate, 1000" << std::endl;
    data.updateRows(data.selectRowsMatching(2, nullptr), 2, 1000); 
    data.selectRowsMatching(2, 1000).forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    data.addColumn();

    std::cout << "select 3, null" << std::endl;
    data.selectRowsMatching(3, nullptr).forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;

    std::cout << "udpate, Update" << std::endl;
    data.updateRows(data.selectRowsMatching(3, nullptr), 3, "Update"); 
    data.selectRowsMatching(3, "Update").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    data.updateRows(data.selectRowsMatching(3, "Update"), 3, nullptr); 
    data.selectRowsMatching(3, nullptr).forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    return 0;
}