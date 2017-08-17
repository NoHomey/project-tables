#include <iostream>
#include "../String/ConstString/ConstString.h"
#include "../FileIO/Writer/Writer.h"
#include "../FileIO/Writer/OutputFile/OutputFile.h"
#include "../Table/TableTypesOutputer/TableTypesOutputer.h"
#include "../Table/TableData/TableData.h"

TableTypes::Integer integer(TableTypes::Integer i) {
    return i;
}

ColumnMetaData::ColumnType getType(TableTypes::Column col) {
    switch(col) {
        case 0: return ColumnMetaData::Integer;
        case 1: return ColumnMetaData::FractionalNumber;
        default: return ColumnMetaData::String;
    }
}

void write(Writer& file, const TableData& data) {
    const TableTypes::Row rows = data.rowsCount();
    const TableTypes::Column columns = data.columnsCount();
    for(TableTypes::Row row = 0; row < rows; ++row) {
        for(TableTypes::Column col = 0; col < columns; ++col) {
            TableTypesOutputer::output(file, data(row, col), getType(col));
            file << ' ';
        }
        file << '\n';
    }
}

int main() {
    Writer file{"test.txt"};

    TableData data;

    data.addColumn();
    data.addColumn();
    data.addColumn();

    data.insert(integer(0));
    data.insert(3.14);
    data.insert("Text");
    data.insert(Integer::Min);
    data.insert(2.481);
    data.insert("\"Quoted\"");
    data.insert(Integer::Max);
    data.insert(-59.3491);
    data.insert("C:\\temp\\dir");

    write(file, data);

    file.endFile();
    
    return 0;
}