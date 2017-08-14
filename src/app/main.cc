#include "../Renderer/Window/Window.h"
#include "../Renderer/BasicRenderer/BasicRenderer.h"
#include "ModelAdaptors/ListTableModelAdaptor/ListTableModelAdaptor.h"
#include "ModelAdaptors/ListTablesModelAdaptor/ListTablesModelAdaptor.h"
#include "../Components/List/ListComponent/ListComponent.h"
#include "Tables/Tables.h"
#include <cstdio>
#include <unistd.h>

int main() {
    Window::syncSizes();
    Window::registerSignal();
    BasicRenderer::setup();

    Tables& tables = Tables::getAllTables();

    Table t1{"table1"};
    t1.addColumn({ColumnMetaData::Integer});
    t1.addColumn({ColumnMetaData::Integer});
    t1.addColumn({ColumnMetaData::Integer});
    t1.addColumn({ColumnMetaData::Integer});
    tables.addTable(&t1);

    Table t2{"AAA"};
    tables.addTable(&t2);

    Table t3{"LongStoryShort"};
    tables.addTable(&t3);

    ListComponent::inject(ListTablesModelAdaptor::adapt(Tables::getAllTables())).render();

    for(size_t i  = 0; i < 2; ++i) {
        Window::syncSizes();
        ListComponent::inject(ListTablesModelAdaptor::adapt(Tables::getAllTables())).render();
        sleep(4);

        Window::syncSizes();
        ListComponent::inject(ListTableModelAdaptor::adapt(
            Tables::getAllTables().getTableByName(ConstString{"table1"})
        )).render();
        sleep(4);

        Window::syncSizes();
        ListComponent::inject(ListTableModelAdaptor::adapt(
            Tables::getAllTables().getTableByName(ConstString{"LongStoryShort"})
        )).render();
        sleep(4);
    }

    return 0;
}