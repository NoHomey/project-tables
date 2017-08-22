#include "TableOutputerToFile.h"
#include "../../TypesOutputer/TypesOutputer.h"

const char* TableOutputerToFile::ConstStringToCString(ConstString& file) {
    const size_t fileLength = file.length();
    char* fileName = new char[fileLength + 1];
    for(size_t index = 0; index < fileLength; ++index) {
        fileName[index] = file[index];
    }
    fileName[fileLength] = '\0';
    return fileName;
}

TableOutputerToFile::TableOutputerToFile(const Table& table) noexcept
: table{table} { }

void TableOutputerToFile::outputTableName(Writer& writer) {
    TypesOutputer::output(writer, ConstString::fromString(table.getName()));
    if(table.getColumnsMetaData().size() > 0) {
        writer << '\n';
    }
}

void TableOutputerToFile::outputColumnTypes(Writer& writer) {
    const DynamicArray<ColumnMetaData>& columnsMetaData = table.getColumnsMetaData();
    const size_t columnsCount = columnsMetaData.size();
    const size_t lastIndex = columnsCount - 1;
    for(size_t index = 0; index < columnsCount; ++index) {
        TypesOutputer::output(writer, ColumnMetaData::columnTypeAsString((columnsMetaData[index].getType())));
        if(index < lastIndex) {
            writer << ' ';
        }
    }
    if(table.data().rowsCount() > 0) {
        writer << '\n';
    }
}

void TableOutputerToFile::outputTableData(Writer& writer) {
    const TableData& tableData = table.data();
    const TableTypes::Row rowsCount = tableData.rowsCount();
    const TableTypes::Column columnsCount = tableData.columnsCount();
    const DynamicArray<ColumnMetaData>& columnsMetaData = table.getColumnsMetaData();
    const size_t lastColumnIndex = columnsCount - 1;
    const size_t lastRowIndex = rowsCount - 1;
    bool isNotLastColumnIndex;
    for(size_t rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
        for(size_t columnIndex = 0; columnIndex < columnsCount; ++columnIndex) {
            TypesOutputer::output(writer, tableData(rowIndex, columnIndex), columnsMetaData[columnIndex].getType());
            isNotLastColumnIndex = columnIndex < lastColumnIndex;
            if(isNotLastColumnIndex || (rowIndex < lastRowIndex)) {
                writer << (isNotLastColumnIndex ? ' ' : '\n');
            }
        }
    }
}

void TableOutputerToFile::outputToFile(ConstString& file) {
    const char* fileName = ConstStringToCString(file);
    Writer writer{{fileName}};
    outputTableName(writer);
    outputColumnTypes(writer);
    outputTableData(writer);
    writer.endFile();
    delete[] fileName;
}