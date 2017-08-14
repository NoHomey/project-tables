.PHONY: clean

COMPILER = g++ -std=c++14

Renderer = ../Renderer

String = ../String

List = ../Components/List

app = ../app

ModelAdaptors = $(app)/ModelAdaptors

OwnDeps = $(1)/$(2)/$(2).cc $(1)/$(2)/$(2).h

app: ../app/main.cc Window.o BasicRenderer.o CenteredRenderer.o Centered.o String.o ConstString.o FixedSizeString.o\
ListComponent.o ListTablesModelAdaptor.o ColumnMetaData.o Table.o Tables.o ListTableModelAdaptor.o
	$(COMPILER) $^

Window.o: $(call OwnDeps,$(Renderer),Window)
	$(COMPILER) -c $<

Centered.o: $(call OwnDeps,$(Renderer),Centered)
	$(COMPILER) -c $<

BasicRenderer.o: $(call OwnDeps,$(Renderer),BasicRenderer)
	$(COMPILER) -c $<

CenteredRenderer.o: $(call OwnDeps,$(Renderer),CenteredRenderer) BasicRenderer.o
	$(COMPILER) -c $<

String.o: $(String)/String.cc $(String)/String.h
	$(COMPILER) -c $<

ConstString.o: $(call OwnDeps,$(String),ConstString) String.o
	$(COMPILER) -c $<

FixedSizeString.o: $(call OwnDeps,$(String),FixedSizeString) String.o
	$(COMPILER) -c $<

ListComponent.o: $(call OwnDeps,$(List),ListComponent)
	$(COMPILER) -c $<

ColumnMetaData.o: $(call OwnDeps,$(app)/Table,ColumnMetaData)
	$(COMPILER) -c $<

Table.o: $(call OwnDeps,$(app),Table) ColumnMetaData.o
	$(COMPILER) -c $<

Tables.o: $(call OwnDeps,$(app),Tables) Table.o
	$(COMPILER) -c $<

ListTablesModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListTablesModelAdaptor)
	$(COMPILER) -c $<

ListTableModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListTableModelAdaptor)
	$(COMPILER) -c $<

clean:
	rm *.o a.out