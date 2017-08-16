.PHONY: clean leakCheck run

COMPILER = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

Executable = ./a.out

Renderer = ../Renderer

String = ../String

List = ../Components/List

app = ../app

ModelAdaptors = $(app)/ModelAdaptors

SharedPtr = ../SharedPtr

Table = $(app)/Table

TableData = $(Table)/TableData

OwnDeps = $(1)/$(2)/$(2).cc $(1)/$(2)/$(2).h

app: ../app/main.cc Window.o BasicRenderer.o CenteredRenderer.o Centered.o String.o ConstString.o FixedSizeString.o\
ListComponent.o ListTablesModelAdaptor.o ColumnMetaData.o SharedPtr.o RowsFilterResult.o TableData.o Table.o Tables.o ListTableModelAdaptor.o
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

ColumnMetaData.o: $(call OwnDeps,$(Table),ColumnMetaData)
	$(COMPILER) -c $<

SharedPtr.o: $(SharedPtr)/SharedPtr.cc $(SharedPtr)/SharedPtr.htd
	$(COMPILER) -c $<

RowsFilterResult.o: $(call OwnDeps,$(TableData),RowsFilterResult)
	$(COMPILER) -c $<

TableData.o: $(call OwnDeps,$(Table),TableData) SharedPtr.o FixedSizeString.o RowsFilterResult.o
	$(COMPILER) -c $<

Table.o: $(call OwnDeps,$(app),Table) ColumnMetaData.o TableData.o
	$(COMPILER) -c $<

Tables.o: $(call OwnDeps,$(app),Tables) Table.o
	$(COMPILER) -c $<

ListTablesModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListTablesModelAdaptor)
	$(COMPILER) -c $<

ListTableModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListTableModelAdaptor)
	$(COMPILER) -c $<

clean:
	rm -f *.o $(Executable)

leakCheck:
	valgrind $(Executable)

run:
	$(Executable)