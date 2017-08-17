#include <iostream>
#include "../String/ConstString/ConstString.h"
#include "../FileIO/Writer/Writer.h"
#include "../FileIO/Writer/OutputFile/OutputFile.h"
#include "../Table/TableTypesOutputer/TableTypesOutputer.h"

TableTypes::Integer integer(TableTypes::Integer i) {
    return i;
}

int main() {
    Writer file{"test.txt"};
    TableTypesOutputer::output(file, integer(12));
    file << ' ';
    TableTypesOutputer::output(file, integer(0));
    file << ' ';
    TableTypesOutputer::output(file, integer(Integer::Min));
    file << ' ';
    TableTypesOutputer::output(file, integer(Integer::Max));
    file << ' ';
    TableTypesOutputer::output(file, integer(102048548));
    file << ' ';
    TableTypesOutputer::output(file, 3.14);
    file << ' ';
    TableTypesOutputer::output(file, 2.481);
    file << ' ';
    TableTypesOutputer::output(file, -59.3491);
    file.endFile();
    
    return 0;
}