#include <iostream>
#include "Table/TableData/TableData.h"

void print(const TableData& data) {
    const TableTypes::Row rows = data.rowsCount();
    std::cout << "--------------------------" << std::endl;
    for(TableTypes::Row row = 0; row < rows; ++row) {
        std::cout << data(row, 0).getCopy<TableTypes::Integer>() << ' ' << data(row, 1).getConstRef<TableTypes::String>()[0] << std::endl;
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
    data.insert(2);
    data.insert("Test");
    data.insert(2);
    data.insert("Ovi");
    data.insert(2);
    data.insert("Ovi");
    data.insert(9);
    data.insert("Ivo");
    data.insert(9);
    data.insert("Ivo");

    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;

    std::cout << "select 1, Ovi" << std::endl;
    data.selectRowsMatching(1, "Ovi").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    print(data);

    data.deleteRows(data.selectRowsMatching(1, "Ovi"));

    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;
    
    std::cout << "select 1, Ovi" << std::endl;
    data.selectRowsMatching(1, "Ovi").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });

    print(data);

    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;
    
    std::cout << "select 1, Test" << std::endl;
    data.selectRowsMatching(1, "Test").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });
    
    print(data);
    
    data.deleteRows(data.selectRowsMatching(1, "Test"));
    
    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;
        
    std::cout << "select 1, Test" << std::endl;
    data.selectRowsMatching(1, "Test").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });
    
    print(data);

    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;
    
    std::cout << "select 1, Test" << std::endl;
    data.selectRowsMatching(1, "Test").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });
    
    print(data);
    
    data.deleteRows(data.selectRowsMatching(1, "Test"));
    
    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;
        
    std::cout << "select 1, Test" << std::endl;
    data.selectRowsMatching(1, "Test").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });
    
    print(data);

    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;
    
    std::cout << "select 1, Ivo" << std::endl;
    data.selectRowsMatching(1, "Ivo").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });
    
    print(data);
    
    data.deleteRows(data.selectRowsMatching(1, "Ivo"));
    
    std::cout << "data " << data.rowsCount() << ' ' << data.columnsCount() << std::endl;
        
    std::cout << "select 1, Ivo" << std::endl;
    data.selectRowsMatching(1, "Ivo").forEach([](TableTypes::Row row, size_t index) {
        std::cout << row << ' ' << index << std::endl;
    });
    
    print(data);

    return 0;
}