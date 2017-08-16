#include "RowsFilterResult.h"
#include <new>

RowsFilterResult::RowsFilterResult() noexcept
: allCount{0}, filteredRows{} { }

RowsFilterResult RowsFilterResult::allRows(size_t all) noexcept {
    return {all};
}

RowsFilterResult::RowsFilterResult(TableTypes::Row unFilteredRowsCount)
: allCount{0}, filteredRows{unFilteredRowsCount} { }

RowsFilterResult::RowsFilterResult(size_t allCount) noexcept
: allCount{allCount}, filteredRows{} { }

void RowsFilterResult::addRow(TableTypes::Row row) noexcept {
    if((allCount == 0) && !filteredRows.isFull()) {
        return filteredRows.push(row);
    }
}

void RowsFilterResult::optimize() {
    if(filteredRows.isFull() && !filteredRows.isEmpty()) {
        allCount = filteredRows.capacity();
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