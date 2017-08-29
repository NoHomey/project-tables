#include "RowsFilterResult.h"
#include <new>

size_t RowsFilterResult::calculateInitialCapacity(TableTypes::Row unFilteredRowsCount) noexcept {
    if(unFilteredRowsCount < minUnused) {
        return unFilteredRowsCount;
    }
    return unFilteredRowsCount / 2 + (unFilteredRowsCount % 2);
}

RowsFilterResult::RowsFilterResult() noexcept
: allCount{0}, filteredRows{} { }

RowsFilterResult RowsFilterResult::allRows(size_t all) noexcept {
    return {all, 0};
}

RowsFilterResult::RowsFilterResult(TableTypes::Row unFilteredRowsCount)
: allCount{0}, filteredRows{calculateInitialCapacity(unFilteredRowsCount)} { }

RowsFilterResult::RowsFilterResult(size_t allCount, int) noexcept
: allCount{allCount}, filteredRows{} { }

void RowsFilterResult::addRow(TableTypes::Row row) noexcept {
    if(allCount == 0) {
        return filteredRows.push(row);
    }
}

void RowsFilterResult::optimize(TableTypes::Row rowsCount) {
    if(filteredRows.size() == rowsCount) {
        allCount = rowsCount;
        filteredRows.clear();
        return;
    }
    if(allCount == 0) {
        const size_t unused = filteredRows.unused();
        if((unused > minUnused) && (unused > ((filteredRows.capacity() / 8) * 3))) {
            try {
                filteredRows.shrinkToFit();
            } catch(std::bad_alloc& error) { }
        }
    }
}

size_t RowsFilterResult::count() const noexcept {
    return allCount > 0 ? allCount : filteredRows.size();
}

TableTypes::Row RowsFilterResult::operator[](TableTypes::Row row) const noexcept {
    return allCount > 0 ? row : filteredRows[row];
}

bool RowsFilterResult::isEmpty() const noexcept {
    return count() == 0;
}