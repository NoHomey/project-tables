.PHONY: clean leakCheck allocs run stringifyIntegerLimits dependencies removeDeps compileAll

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

Messages = $(app)/Messages

Action = $(Actions)/Action

Help = $(Actions)/Help

dependencies = ../dependencies

fpconv = $(dependencies)/fpconv

OwnDeps = $(1)/$(2)/$(2).cc $(1)/$(2)/$(2).h

Templates = ../Container/DynamicArrayBase/DynamicArrayBase.htd ../Container/DynamicArray/DynamicArray.htd\
../Container/MoveDynamicArray/MoveDynamicArray.htd ../SharedPtr/SharedPtr.htd

Objects = Window.o BasicRenderer.o CenteredRenderer.o Centered.o String.o ConstString.o FixedSizeString.o ListComponent.o\
ListTablesModelAdaptor.o ColumnMetaData.o SharedPtr.o RowsFilterResult.o TableData.o Table.o Tables.o ListTableModelAdaptor.o\
OutputFile.o Writer.o fpconv.o TypesOutputer.o CharSequenceParser.o Action.o ShowTables.o Argument.o InfoModel.o InfoComponent.o\
Message.o UnknownQueryCommand.o MissingTableName.o MessageContainingTableName.o InvalidTableName.o TableNotFound.o\
InvalidSymbolAtPosition.o TableNameParser.o ParseTableName.o Describe.o SuccessfullyRenamedTable.o NoRename.o Rename.o\
NewNameIsNotUnique.o TableCreated.o TableExists.o CreateTable.o ListOfCommands.o Help.o Application.o

compileAll: $(Templates) app

app: ../app/main.cc $(Objects)
	$(COMPILER) -pthread $^

all: stringifyIntegerLimits dependencies app

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

InfoModel.o: $(call OwnDeps,$(Info),InfoModel)
	$(COMPILER) -c $<

InfoComponent.o: $(call OwnDeps,$(Info),InfoComponent) Window.o CenteredRenderer.o InfoModel.o
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

UnknownQueryCommand.o: $(call OwnDeps,$(Messages),UnknownQueryCommand) ConstString.o FixedSizeString.o\
TypesOutputer.o InfoModel.o
	$(COMPILER) -c $<

Action.o: $(call OwnDeps,$(Actions),Action) Tables.o ConstString.o CharSequenceParser.o UnknownQueryCommand.o
	$(COMPILER) -c $<

ShowTables.o: $(call OwnDeps,$(Actions),ShowTables) Action.o ListComponent.o
	$(COMPILER) -c $<

Message.o: $(call OwnDeps,$(Actions),Message) Action.o InfoComponent.o InfoModel.o
	$(COMPILER) -c $<

MissingTableName.o: $(call OwnDeps,$(Messages),MissingTableName) String.o ConstString.o TypesOutputer.o
	$(COMPILER) -c $<

MessageContainingTableName.o: $(call OwnDeps,$(Messages),MessageContainingTableName) String.o ConstString.o FixedSizeString.o TypesOutputer.o
	$(COMPILER) -c $<

InvalidTableName.o: $(call OwnDeps,$(Messages),InvalidTableName) MessageContainingTableName.o
	$(COMPILER) -c $<

TableNotFound.o: $(call OwnDeps,$(Messages),TableNotFound) MessageContainingTableName.o
	$(COMPILER) -c $<

ParseTableName.o: $(call OwnDeps,$(Actions),ParseTableName) Action.o TableNameParser.o Message.o
	$(COMPILER) -c $<

Describe.o: $(call OwnDeps,$(Actions),Describe) Action.o TableNameParser.o ParseTableName.o\
ListComponent.o ListTableModelAdaptor.o Message.o
	$(COMPILER) -c $<

SuccessfullyRenamedTable.o: $(call OwnDeps,$(Messages),SuccessfullyRenamedTable) String.o ConstString.o FixedSizeString.o TypesOutputer.o
	$(COMPILER) -c $<

NoRename.o: $(call OwnDeps,$(Messages),NoRename) MessageContainingTableName.o
	$(COMPILER) -c $<

NewNameIsNotUnique.o: $(call OwnDeps,$(Messages),NewNameIsNotUnique) MessageContainingTableName.o
	$(COMPILER) -c $<

Rename.o: $(call OwnDeps,$(Actions),Rename) Action.o TableNameParser.o ParseTableName.o SuccessfullyRenamedTable.o\
NoRename.o NewNameIsNotUnique.o
	$(COMPILER) -c $<

TableCreated.o: $(call OwnDeps,$(Messages),TableCreated) MessageContainingTableName.o
	$(COMPILER) -c $<

TableExists.o: $(call OwnDeps,$(Messages),TableExists) MessageContainingTableName.o
	$(COMPILER) -c $<

CreateTable.o: $(call OwnDeps,$(Actions),CreateTable) Action.o TableNameParser.o ParseTableName.o Message.o\
TableCreated.o TableExists.o
	$(COMPILER) -c $<

ListOfCommands.o: $(call OwnDeps,$(Help),ListOfCommands)
	$(COMPILER) -c $<

Help.o: $(call OwnDeps,$(Actions),Help) ListComponent.o ListOfCommands.o
	$(COMPILER) -c $<

Application.o: $(call OwnDeps,$(app),Application)
	$(COMPILER) -c -pthread $<

dependencies:
	cd ../dependencies && $(MAKE)

removeDeps:
	cd ../dependencies && $(MAKE) remove

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