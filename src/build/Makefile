.PHONY: clean leakCheck allocs run stringifyIntegerLimits dependencies removeDeps compileAll

COMPILER = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

Executable = ./a.out

Renderer = ../Renderer

String = ../String

Components = ../Components/

List = $(Components)/List

Info = $(Components)/Info

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

define FileIOMessage

$(1).o: $(call OwnDeps,$(Messages)/FileIO/$(2),$(1)) FileIOMessage.o
	$(COMPILER) -c $$<

endef

OpenMessages = CannotCreateFile CannotOpenFile FileIsLocatedOnReadOnlyFileSystem FileIsSealed FileIsTooLarge\
FileNameIsTooLong ItIsADirectory PermitionDenied

WriteMessages = CannotWrite FileIsTooBig FileSystemDiskBlocksQuotaExhausted LowLevelException UnexpectedWriteError

OpenMessageObjects = $(addsuffix .o,$(OpenMessages))

WriteMessageObjects = $(addsuffix .o,$(WriteMessages))

Templates = ../Container/DynamicArrayBase/DynamicArrayBase.htd ../Container/DynamicArray/DynamicArray.htd\
../Container/MoveDynamicArray/MoveDynamicArray.htd ../SharedPtr/SharedPtr.htd\
$(Actions)/ActionRequiringTable/ActionRequiringTable.htd $(Actions)/ActionRequiringTable/ActionRequiringTable.tci\
$(Components)/ComponentWithModel/ComponentWithModel.htd $(Components)ComponentWithModel/ComponentWithModel.tci\
$(Parsers)/ParseResult/ParseResult.htd $(Parsers)/ParseResult/ParseResult.tci 

Objects = Window.o BasicRenderer.o CenteredRenderer.o Centered.o String.o ConstString.o FixedSizeString.o Model.o ListModel.o ListComponent.o\
ListTablesModelAdaptor.o ColumnMetaData.o SharedPtr.o RowsFilterResult.o TableData.o Table.o Tables.o ListTableModelAdaptor.o\
OutputFile.o Writer.o fpconv.o TypesOutputer.o CharSequenceParser.o Action.o ShowTables.o Argument.o InfoModel.o InfoComponent.o\
UnknownQueryCommand.o MissingArgument.o MissingTableName.o MessageContainingTableName.o InvalidTableName.o TableNotFound.o\
TokenException.o InvalidSymbolAtPosition.o TableNameParser.o ParseTableName.o Describe.o TableRenamed.o NoRename.o Rename.o\
NewNameIsNotUnique.o TableCreated.o TableExists.o CreateTable.o InvalidColumnType.o ListCommandsModelAdaptor.o MissingColumnType.o\
InvalidColumnType.o NewColumnAdded.o ColumnTypeParser.o AddColumn.o TableOutputerToFile.o MissingFileName.o ParseFileName.o\
TableSaved.o FileIOMessage.o $(OpenMessageObjects) $(WriteMessageObjects) Save.o IntegerParser.o ColumnNumberParser.o FractionalNumberParser.o\
#Help.o Quit.o Application.o 

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

Model.o: $(call OwnDeps,$(Components),Model)
	$(COMPILER) -c $<

ListModel.o: $(call OwnDeps,$(List),ListModel)
	$(COMPILER) -c $<

ListComponent.o: $(call OwnDeps,$(List),ListComponent) Window.o CenteredRenderer.o TypesOutputer.o ListModel.o
	$(COMPILER) -c $<

InfoModel.o: $(call OwnDeps,$(Info),InfoModel) Model.o
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

ListTablesModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListTablesModelAdaptor) ListModel.o
	$(COMPILER) -c $<

ListTableModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListTableModelAdaptor) ListModel.o
	$(COMPILER) -c $<

ListCommandsModelAdaptor.o: $(call OwnDeps,$(ModelAdaptors),ListCommandsModelAdaptor) ListModel.o
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

TokenException.o: $(call OwnDeps,$(Exceptions),TokenException)
	$(COMPILER) -c $<

InvalidSymbolAtPosition.o: $(call OwnDeps,$(Exceptions),InvalidSymbolAtPosition) TokenException.o
	$(COMPILER) -c $<

TableNameParser.o: $(call OwnDeps,$(Parsers),TableNameParser) CharSequenceParser.o InvalidSymbolAtPosition.o
	$(COMPILER) -c $<

ColumnTypeParser.o: $(call OwnDeps,$(Parsers),ColumnTypeParser) CharSequenceParser.o TokenException.o ColumnMetaData.o
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

MissingArgument.o: $(call OwnDeps,$(Messages),MissingArgument) String.o ConstString.o TypesOutputer.o
	$(COMPILER) -c $<

MissingTableName.o: $(call OwnDeps,$(Messages),MissingTableName) MissingArgument.o
	$(COMPILER) -c $<

MessageContainingTableName.o: $(call OwnDeps,$(Messages),MessageContainingTableName) String.o ConstString.o FixedSizeString.o TypesOutputer.o
	$(COMPILER) -c $<

InvalidTableName.o: $(call OwnDeps,$(Messages),InvalidTableName) MessageContainingTableName.o
	$(COMPILER) -c $<

TableNotFound.o: $(call OwnDeps,$(Messages),TableNotFound) MessageContainingTableName.o
	$(COMPILER) -c $<

ParseTableName.o: $(call OwnDeps,$(Actions),ParseTableName) Action.o TableNameParser.o MissingTableName.o
	$(COMPILER) -c $<

Describe.o: $(call OwnDeps,$(Actions),Describe) Action.o TableNameParser.o ParseTableName.o\
ListComponent.o ListTableModelAdaptor.o
	$(COMPILER) -c $<

TableRenamed.o: $(call OwnDeps,$(Messages),TableRenamed) String.o ConstString.o FixedSizeString.o TypesOutputer.o
	$(COMPILER) -c $<

NoRename.o: $(call OwnDeps,$(Messages),NoRename) MessageContainingTableName.o
	$(COMPILER) -c $<

NewNameIsNotUnique.o: $(call OwnDeps,$(Messages),NewNameIsNotUnique) MessageContainingTableName.o
	$(COMPILER) -c $<

Rename.o: $(call OwnDeps,$(Actions),Rename) Action.o TableNameParser.o ParseTableName.o TableRenamed.o\
NoRename.o NewNameIsNotUnique.o
	$(COMPILER) -c $<

TableCreated.o: $(call OwnDeps,$(Messages),TableCreated) MessageContainingTableName.o
	$(COMPILER) -c $<

TableExists.o: $(call OwnDeps,$(Messages),TableExists) MessageContainingTableName.o
	$(COMPILER) -c $<

CreateTable.o: $(call OwnDeps,$(Actions),CreateTable) Action.o TableNameParser.o ParseTableName.o TableCreated.o TableExists.o
	$(COMPILER) -c $<

InvalidColumnType.o: $(call OwnDeps,$(Messages),InvalidColumnType) String.o ConstString.o FixedSizeString.o InfoModel.o TypesOutputer.o
	$(COMPILER) -c $<

MissingColumnType.o: $(call OwnDeps,$(Messages),MissingColumnType) String.o ConstString.o FixedSizeString.o InfoModel.o TypesOutputer.o
	$(COMPILER) -c $<

NewColumnAdded.o: $(call OwnDeps,$(Messages),NewColumnAdded) MessageContainingTableName.o
	$(COMPILER) -c $<

AddColumn.o: $(call OwnDeps,$(Actions),AddColumn) Action.o TableNameParser.o ParseTableName.o\
InvalidColumnType.o MissingColumnType.o NewColumnAdded.o ColumnMetaData.o
	$(COMPILER) -c $<

Help.o: $(call OwnDeps,$(Actions),Help) ListComponent.o ListCommandsModelAdaptor.o
	$(COMPILER) -c $<

Quit.o: $(call OwnDeps,$(Actions),Quit)
	$(COMPILER) -c $<

TableOutputerToFile.o: $(call OwnDeps,$(Table),TableOutputerToFile) ConstString.o Writer.o TypesOutputer.o
	$(COMPILER) -c $<

MissingFileName.o: $(call OwnDeps,$(Messages),MissingFileName) MissingArgument.o
	$(COMPILER) -c $<

ParseFileName.o: $(call OwnDeps,$(Actions),ParseFileName) Action.o MissingFileName.o
	$(COMPILER) -c $<

TableSaved.o: $(call OwnDeps,$(Messages),TableSaved) MessageContainingTableName.o
	$(COMPILER) -c $<

FileIOMessage.o: $(call OwnDeps,$(Messages)/FileIO,FileIOMessage) InfoModel.o ConstString.o FixedSizeString.o TypesOutputer.o
	$(COMPILER) -c $<

$(foreach message,$(OpenMessages),$(eval $(call FileIOMessage,$(message),OpenMessage)))

$(foreach message,$(WriteMessages),$(eval $(call FileIOMessage,$(message),WriteMessage)))

Save.o: $(call OwnDeps,$(Actions),Save) TableOutputerToFile.o MissingFileName.o ParseFileName.o\
TableSaved.o FileIOMessage.o $(OpenMessageObjects) $(WriteMessageObjects)
	$(COMPILER) -c $<

IntegerParser.o: $(call OwnDeps,$(Parsers),IntegerParser) CharSequenceParser.o InvalidSymbolAtPosition.o TokenException.o
	$(COMPILER) -c $<

ColumnNumberParser.o: $(call OwnDeps,$(Parsers),ColumnNumberParser) IntegerParser.o
	$(COMPILER) -c $<

FractionalNumberParser.o: $(call OwnDeps,$(Parsers),FractionalNumberParser) IntegerParser.o
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