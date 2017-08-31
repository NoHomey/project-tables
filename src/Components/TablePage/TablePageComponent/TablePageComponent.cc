#include "TablePageComponent.h"
#include "../../../Renderer/CenteredRenderer/CenteredRenderer.h"
#include "../../../TypesOutputer/TypesOutputer.h"

TablePageComponent::TablePageComponent(const Table& table, RowsFilterResult&& filteredRows) noexcept
: model{table, std::move(filteredRows)}, columnLengths{}, pageStartRow{0}, pageStartColumn{0} { }

size_t TablePageComponent::columnLength(TableTypes::Column column, TableTypes::Row begin, TableTypes::Row end) const noexcept {
    size_t maxLength = 0;
    size_t currrentLength = 0;
    for(TableTypes::Row row = begin; row < end; ++row) {
        currrentLength = TypesOutputer::outputCount(model(row, column), model.columnType(column));
        if(currrentLength > maxLength) {
            maxLength = currrentLength;
        }
    }
    return maxLength;
}

Window::size TablePageComponent::calculateColumnLengthsFittingInWindow(
    TableTypes::Row rowBegin, TableTypes::Row rowEnd,
    TableTypes::Column columnBegin, TableTypes::Column columnEnd
) {
    const Window::size windowWidth = Window::getWidth();
    size_t width = 0;
    size_t currentColumnLength = 0;
    columnLengths.empty();
    for(TableTypes::Column column = columnBegin; column < columnEnd; ++column) {
        currentColumnLength = columnLength(column, rowBegin, rowEnd); 
        if((width + currentColumnLength) > windowWidth) {
            return width;
        }
        width += currentColumnLength;
        columnLengths.push(currentColumnLength);
    }
    return width;
}

void TablePageComponent::loopSymbol(CharOutputStream& outputStream, Window::size count, char symbol) {
    for(Window::size counter = 0; counter < count; ++ counter) {
        outputStream << symbol;
    }
}
 
void TablePageComponent::addBlank(CharOutputStream& outputStream, Window::size count) {
    loopSymbol(outputStream, count, ' ');
}

void TablePageComponent::addHorizontalLine(CharOutputStream& outputStream) {
    loopSymbol(outputStream, Window::getWidth() - 1, '-');
    outputStream << '\n';
}

void TablePageComponent::renderWholeTable(Window::size padding, Window::size rowsListWidth, Window::size width) {
    const TableTypes::Row rowsCount = model.rowsCount();
    const TableTypes::Column columnsCount = model.columnsCount();
    CenteredRenderer& renderer = CenteredRenderer::getRenderer();
    const TableTypes::Column lastColumn = columnsCount - 1;
    CenteredRenderer::clear();
    TableTypes::Column columnNumber;
    Window::size count;
    addBlank(renderer, rowsListWidth);
    renderer << '|';
    for(TableTypes::Column column = 0; column < columnsCount; ++column) {
        columnNumber  = column + 1;
        count = TypesOutputer::outputCount(columnNumber);
        addBlank(renderer, padding);
        TypesOutputer::output(renderer, columnNumber);
        addBlank(renderer, columnLengths[column] - count + padding);
        if(column != lastColumn) {
            renderer << '|';
        }
    }
    loopSymbol(renderer, width, '-');
    ColumnMetaData::ColumnType columnType;
    TableTypes::Row rowNumber;
    for(TableTypes::Row row = 0; row < rowsCount; ++row) {
        rowNumber = model.tableRowNumber(row);
        TypesOutputer::output(renderer, rowNumber);
        addBlank(renderer, rowsListWidth - TypesOutputer::outputCount(rowNumber));
        renderer << '|';
        for(TableTypes::Column column = 0; column < columnsCount; ++ column) {
            const SharedPtr& cell = model(row, column);
            columnType = model.columnType(column);
            count = TypesOutputer::outputCount(cell, columnType);
            addBlank(renderer, padding);
            TypesOutputer::output(renderer, cell, columnType);
            addBlank(renderer, columnLengths[column] - count + padding);
            if(column != lastColumn) {
                renderer << '|';
            }
        }
    }
}

bool TablePageComponent::renderWholeTable() {
    const TableTypes::Column columnsCount = model.columnsCount();
    if(columnsCount > Window::getHeight()) {
        return false;
    }
    const TableTypes::Row rowsCount = model.rowsCount();
    Window::size width = calculateColumnLengthsFittingInWindow(0, rowsCount, 0, columnsCount);
    if(columnLengths.size() > columnsCount) {
        return false;
    }
    width += columnsCount > 1 ? (columnsCount - 1) : 0;
    const Window::size rowsListWidth = TypesOutputer::outputCount(model.tableRowNumber(rowsCount - 1)) + 1;
    width += (rowsListWidth + 1);
    const Window::size height = rowsCount + 2;    
    const Window::size columsPadding = 2 * columnsCount;
    Window::size padding = maxWholeTableCellHorizontalPadding * columsPadding;
    Window::size queryWidth;
    for(Window::size reducePadding = 0; reducePadding <= maxWholeTableCellHorizontalPadding; ++reducePadding) {
        queryWidth = width + padding;
        if(CenteredRenderer::queryCentered(queryWidth, height).bordered().atLeastMargin(1, 1).exec()) {
            renderWholeTable(maxWholeTableCellHorizontalPadding - reducePadding, rowsListWidth, queryWidth);
            return true;
        }
        padding -= columsPadding;
    }
    return false;
}

void TablePageComponent::renderTablePage() {
    const Window::size windowWidth = Window::getWidth();
    const Window::size windowHeight = Window::getHeight();
    const TableTypes::Row rowsCount = model.rowsCount();
    const TableTypes::Column columnsCount = model.columnsCount();
    const TableTypes::Row rowsLeft = rowsCount - pageStartRow;
    bool borderBottom = false;
    Window::size height = windowHeight;
    TableTypes::Row pageRows = height - 2;
    if(pageRows > rowsLeft) {
        pageRows = rowsLeft;
        if(windowHeight > (rowsLeft + 3)) {
            height = rowsLeft + 3;
            borderBottom = true;
        }
    }
    const TableTypes::Row pageEndRow = pageStartRow + pageRows;
    const Window::size rowsListWidth = TypesOutputer::outputCount(model.tableRowNumber(pageEndRow - 1)) + 1;
    Window::size width = calculateColumnLengthsFittingInWindow(pageStartRow, pageEndRow, pageStartColumn, columnsCount);
    width += (rowsListWidth + columnLengths.size()) + 2;
    while(width > windowWidth) {
        width -= (columnLengths.last() + 1);
        columnLengths.pop();
    }
    const TableTypes::Column pageColumns = columnLengths.size();
    const Window::size blank = windowWidth - width; 
    Window::size padding = blank / pageColumns;
    const Window::size reminder = (blank % pageColumns);
    for(Window::size i = 0; i < reminder; ++i) {
        ++columnLengths[i];
    }
    const Window::size leftPadding = padding / 2;
    const Window::size rightPadding = leftPadding + padding % 2;
    BasicRenderer& basicRenderer = BasicRenderer::getRenderer();
    basicRenderer.ensureCapacity(height * windowWidth + (windowHeight - height));
    basicRenderer.clear();
    addBlank(basicRenderer, rowsListWidth);
    basicRenderer << '|';
    const TableTypes::Column pageEndColumn = pageStartColumn + pageColumns;
    for(TableTypes::Column column = pageStartColumn; column < pageEndColumn; ++column) {
        addBlank(basicRenderer, leftPadding);
        TypesOutputer::output(basicRenderer, column + 1);
        addBlank(basicRenderer, rightPadding + columnLengths[column] - TypesOutputer::outputCount(column + 1));
        basicRenderer << '|';
    }
    basicRenderer << '\n';
    addHorizontalLine(basicRenderer);
    const TableTypes::Row lastRow = pageEndRow - 1;
    TableTypes::Row rowNumber = 0;
    for(TableTypes::Row row = pageStartRow; row < pageEndRow; ++row) {
        rowNumber = model.tableRowNumber(row);
        TypesOutputer::output(basicRenderer, rowNumber);
        addBlank(basicRenderer, rowsListWidth - TypesOutputer::outputCount(rowNumber));
        basicRenderer << '|';
        for(TableTypes::Column column = pageStartColumn; column < pageEndColumn; ++ column) {
            const SharedPtr& cell = model(row, column);
            const ColumnMetaData::ColumnType columnType = model.columnType(column);
            const Window::size count = TypesOutputer::outputCount(cell, columnType);
            addBlank(basicRenderer, leftPadding);
            TypesOutputer::output(basicRenderer, cell, columnType);
            addBlank(basicRenderer, rightPadding + columnLengths[column] - count);
            basicRenderer << '|';
        }
        if(row != lastRow) {
            basicRenderer << '\n';
        }
    }
    if(borderBottom) {
        basicRenderer << '\n';
        addHorizontalLine(basicRenderer);
        loopSymbol(basicRenderer, (windowHeight - (height + 1)), '\n');
    }
    basicRenderer.render();
}

void TablePageComponent::renderTableOnPages() {
    pageStartRow = 0;
    pageStartColumn = 0;
    renderTablePage();
}

void TablePageComponent::render() {
    if(!renderWholeTable()) {
        TablePageComponent::renderTableOnPages();
    }
}