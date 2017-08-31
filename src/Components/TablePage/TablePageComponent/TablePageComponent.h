#pragma once

#include "../TablePageModel/TablePageModel.h"
#include "../../Component.h"
#include "../../../Renderer/Window/Window.h"
#include "../../../CharOutputStream/CharOutputStream.h"

class TablePageComponent: public Component {
public:
    TablePageComponent(const Table& table, RowsFilterResult&& filteredRows) noexcept;
    
    TablePageComponent(const TablePageComponent& other) = delete;
    
    TablePageComponent(TablePageComponent&& other) = delete;
    
    TablePageComponent& operator=(const TablePageComponent& other) = delete;
    
    TablePageComponent& operator=(TablePageComponent&& other) = delete;

public:
    void render();

private:
    size_t columnLength(TableTypes::Column column, TableTypes::Row begin, TableTypes::Row end) const noexcept;

    Window::size calculateColumnLengthsFittingInWindow(
        TableTypes::Row rowBegin, TableTypes::Row rowEnd,
        TableTypes::Column columnBegin, TableTypes::Column columnEnd
    );

    static void loopSymbol(CharOutputStream& outputStream, Window::size count, char symbol);

    static void addBlank(CharOutputStream& outputStream, Window::size count);

    static void addHorizontalLine(CharOutputStream& outputStream);

    void renderWholeTable(Window::size padding, Window::size rowsListWidth, Window::size width);

    bool renderWholeTable();

    void renderTablePage();

    void renderTableOnPages();

private:
    static const Window::size maxWholeTableCellHorizontalPadding = 3; 

private:
    const TablePageModel model;

    DynamicArray<Window::size> columnLengths;

    TableTypes::Row pageStartRow;

    TableTypes::Column pageStartColumn;
};