/*#include "../Renderer/Window/Window.h"
#include "../Renderer/BasicRenderer/BasicRenderer.h"
#include "Actions/Action/Action.h"

#include <unistd.h>

int main() {
    Window::syncSizes();
    Window::registerSignal();
    BasicRenderer::setup();

    Action::takeAction("Showtables");

    for(size_t i  = 0; i < 2; ++i) {
        if(Window::isResized()) {
            Window::syncSizes();
            Action::reRender();
        }
        sleep(2);
    }
    
    return 0;
}*/

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

    for(size_t i  = 0; i < 200; ++i) {
        write(file, data);
        data.addColumn();
        write(file, data);
    }

    file.endFile();
    
    return 0;
}