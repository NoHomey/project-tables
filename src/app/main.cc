#include <iostream>
#include "../String/ConstString/ConstString.h"
#include "../FileIO/Writer/OutputFile/OutputFile.h"

int main() {
    OutputFile file("test.txt");
    ConstString text{"testing it"};

    file.write(text.cString(), text.length());
    
    return 0;
}