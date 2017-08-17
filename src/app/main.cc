#include <iostream>
#include "../String/ConstString/ConstString.h"
#include "../FileIO/Writer/Writer.h"
#include "../FileIO/Writer/OutputFile/OutputFile.h"
#include "../Table/TableTypesOutputer/TableTypesOutputer.h"

int main() {
    Writer file{"test.txt"};
    TableTypesOutputer::output(file, 12);
    file << ' ';
    TableTypesOutputer::output(file, 0);
    file << ' ';
    TableTypesOutputer::output(file, Integer::Min);
    file << ' ';
    TableTypesOutputer::output(file, Integer::Max);
    file << ' ';
    TableTypesOutputer::output(file, 102048548);
    file.endFile();
    
    return 0;
}