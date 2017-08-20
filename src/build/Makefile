.PHONY: clean leakCheck allocs run stringifyIntegerLimits compileAll

COMPILER = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

Executable = ./a.out

Renderer = ../Renderer

String = ../String

List = ../Components/List

Info = ../Components/Info

app = ../app

ModelAdaptors = $(app)/ModelAdaptors

SharedPtr = ../SharedPtr

Table = ../Table

TableData = $(Table)/TableData

FileIO = ../FileIO

Writer = $(FileIO)/Writer

Parsers = ../Parsers

Exceptions = $(Parsers)/Exceptions

Actions = $(app)/Actions

Action = $(Actions)/Action

dependencies = ../dependencies

fpconv = $(dependencies)/fpconv

OwnDeps = $(1)/$(2)/$(2).cc $(1)/$(2)/$(2).h

Templates = ../Container/DynamicArrayBase/DynamicArrayBase.htd ../Container/DynamicArray/DynamicArray.htd\
../Container/MoveDynamicArray/MoveDynamicArray.htd ../SharedPtr/SharedPtr.htd

Objects = Window.o BasicRenderer.o CenteredRenderer.o Centered.o String.o ConstString.o FixedSizeString.o ListComponent.o\
ListTablesModelAdaptor.o ColumnMetaData.o SharedPtr.o RowsFilterResult.o TableData.o Table.o Tables.o ListTableModelAdaptor.o\
OutputFile.o Writer.o fpconv.o TypesOutputer.o CharSequenceParser.o InfoComponent.o #Action.o ShowTables.o Argument.o InfoComponent.o
#InvalidSymbolAtPosition.o TableNameParser.o ParseTableName.o Describe.o Rename.o

compileAll: $(Templates) app

app: ../app/main.cc $(Objects)
	$(COMPILER) $^

Window.o: $(call OwnDeps,$(Renderer),Window)
	$(COMPILER) -c $<

Centered.o: $(call OwnDeps,$(Renderer),Centered)
	$(COMPILER) -c $<

BasicRenderer.o: $(call OwnDeps,$(Renderer),BasicRenderer)
	$(COMPILER) -c $<

CenteredRenderer.o: $(call OwnDeps,$(Renderer),CenteredRenderer) BasicRenderer.o
	$(COMPILER) -c $<

String.o: $(call OwnDeps,..,String)
	$(COMPILER) -c $<

ConstString.o: $(call OwnDeps,$(String),ConstString) String.o
	$(COMPILER) -c $<

FixedSizeString.o: $(call OwnDeps,$(String),FixedSizeString) String.o
	$(COMPILER) -c $<

ListComponent.o: $(call OwnDeps,$(List),ListComponent) Window.o CenteredRenderer.o TypesOutputer.o
	$(COMPILER) -c $<

InfoComponent.o: $(call OwnDeps,$(Info),InfoComponent) Window.o CenteredRenderer.o
	$(COMPILER) -c $<

ColumnMetaData.o: $(call OwnDeps,$(Table),ColumnMetaData)
	$(COMPILER) -c $<

SharedPtr.o: $(SharedPtr)/SharedPtr.cc $(SharedPtr)/SharedPtr.htd
	$(COMPILER) -c $<

RowsFilterResult.o: $(call OwnDeps,$(TableData),RowsFilterResult)
	$(COMPILER) -c $<

TableData.o: $(call OwnDeps,$(Table),TableData) SharedPtr.o FixedSizeString.o RowsFilterResult.o
	$(COMPILER) -c $<

Table.o: $(call OwnDeps,..,Table) ColumnMetaData.o TableData.o
	$(COMPILER) -c $<

Tables.o: $(call OwnDeps,..,Tables) Table.o
	$(COMPILER) -c $<

ListTablesModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListTablesModelAdaptor)
	$(COMPILER) -c $<

ListTableModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListTableModelAdaptor)
	$(COMPILER) -c $<

OutputFile.o: $(call OwnDeps,$(Writer),OutputFile)
	$(COMPILER) -c $<

Writer.o: $(call OwnDeps,$(FileIO),Writer) OutputFile.o
	$(COMPILER) -c $<

fpconv.o: $(fpconv)/fpconv.c $(fpconv)/fpconv.h $(fpconv)/powers.h
	$(COMPILER) -c $<

TypesOutputer.o: $(call OwnDeps,..,TypesOutputer) Writer.o SharedPtr.o String.o ConstString.o\
ColumnMetaData.o fpconv.o
	$(COMPILER) -c $<

CharSequenceParser.o: $(call OwnDeps,$(Parsers),CharSequenceParser) ConstString.o
	$(COMPILER) -c $<

InvalidSymbolAtPosition.o: $(call OwnDeps,$(Exceptions),InvalidSymbolAtPosition)
	$(COMPILER) -c $<

TableNameParser.o: $(call OwnDeps,$(Parsers),TableNameParser) CharSequenceParser.o InvalidSymbolAtPosition.o
	$(COMPILER) -c $<

Argument.o: $(call OwnDeps,$(Action),Argument) ConstString.o FixedSizeString.o
	$(COMPILER) -c $<

Action.o: $(call OwnDeps,$(Actions),Action) Tables.o ConstString.o CharSequenceParser.o
	$(COMPILER) -c $<

ShowTables.o: $(call OwnDeps,$(Actions),ShowTables) Action.o ListComponent.o
	$(COMPILER) -c $<

ParseTableName.o: $(call OwnDeps,$(Actions),ParseTableName) Action.o Error.o TableNameParser.o
	$(COMPILER) -c $<

Describe.o: $(call OwnDeps,$(Actions),Describe) Action.o Error.o TableNameParser.o ParseTableName.o\
ListComponent.o ListTableModelAdaptor.o
	$(COMPILER) -c $<

Rename.o: $(call OwnDeps,$(Actions),Rename) Action.o Error.o Result.o TableNameParser.o ParseTableName.o
	$(COMPILER) -c $<

clean:
	rm -f *.o *.txt $(Executable)

leakCheck:
	valgrind $(Executable)

allocs:
	valgrind --tool=massif --time-unit=B --massif-out-file=massif.out $(Executable)
	ms_print massif.out > allocs.txt
	rm massif.out

run:
	$(Executable)

stringifyIntegerLimits:
	$(COMPILER) stringifyIntegerLimits.cc
	./a.out > ../Table/TableTypes/StringifiedIntegerLimits.h
	rm ./a.out