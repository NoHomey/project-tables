#include "TablePageComponent.h"
#include "../../../Renderer/CenteredRenderer/CenteredRenderer.h"
#include "../../../TypesOutputer/TypesOutputer.h"

TablePageComponent::TablePageComponent(const Table& table, RowsFilterResult&& filteredRows) noexcept
: model{table, std::move(filteredRows)}, columnLengths{} { }

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

void TablePageComponent::addBlank(CharOutputStream& outputStream, Window::size count) {
    for(Window::size counter = 0; counter < count; ++ counter) {
        outputStream << ' ';
    }
}

void TablePageComponent::renderWholeTable(Window::size padding) {
    const TableTypes::Row rowsCount = model.rowsCount();
    const TableTypes::Column columnsCount = model.columnsCount();
    CenteredRenderer& renderer = CenteredRenderer::getRenderer();
    const TableTypes::Column lastColumn = columnsCount - 1;
    CenteredRenderer::clear();
    for(TableTypes::Row row = 0; row < rowsCount; ++row) {
        for(TableTypes::Column column = 0; column < columnsCount; ++ column) {
            const SharedPtr& cell = model(row, column);
            const ColumnMetaData::ColumnType columnType = model.columnType(column);
            const Window::size count = TypesOutputer::outputCount(cell, columnType);
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
    const Window::size columsPadding = 2 * columnsCount;
    Window::size padding = maxWholeTableCellHorizontalPadding * columsPadding;
    for(Window::size reducePadding = 0; reducePadding <= maxWholeTableCellHorizontalPadding; ++reducePadding) {
        if(CenteredRenderer::queryCentered(width + padding, rowsCount).bordered().atLeastMargin(1, 1).exec()) {
            renderWholeTable(maxWholeTableCellHorizontalPadding - reducePadding);
            return true;
        }
        padding -= columsPadding;
    }
    return false;
}

void TablePageComponent::render() {
    if(!renderWholeTable()) {
        BasicRenderer::getRenderer().clearWindow();
    }
}