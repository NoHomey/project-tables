.PHONY: clean leakCheck allocs run stringifyIntegerLimits dependencies removeDeps compileAll

COMPILER = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

Executable = ./a.out

Renderer = ../Renderer

String = ../String

Components = ../Components/

List = $(Components)/List

Info = $(Components)/Info

TablePage = $(Components)/TablePage

app = ../app

ModelAdaptors = $(app)/ModelAdaptors

Container = ../Container

SharedPtr = ../SharedPtr

Table = ../Table

TableData = $(Table)/TableData

FileIO = ../FileIO

Writer = $(FileIO)/Writer

Parsers = ../Parsers

Exceptions = $(Parsers)/Exceptions

Actions = $(app)/Actions

Messages = $(app)/Messages

ColumnNumberParserMessages = $(Messages)/Parsers/ColumnNumberParser

Action = $(Actions)/Action

dependencies = ../dependencies

fpconv = $(dependencies)/fpconv

OwnDeps = $(1)/$(2)/$(2).cc $(1)/$(2)/$(2).h

Template = $(1)/$(2)/$(2).htd

define FileIOMessage
$(1).o: $(call OwnDeps,$(Messages)/FileIO/$(2),$(1)) FileIOMessage.o
	$(COMPILER) -c $$<
endef

define Object
$(2).o: $(call OwnDeps,$(1),$(2)) $(addsuffix .o,$(3))
	$(COMPILER) -c $$<
endef

OpenMessages = CannotCreateFile CannotOpenFile FileIsLocatedOnReadOnlyFileSystem FileIsSealed FileIsTooLarge\
FileNameIsTooLong ItIsADirectory PermitionDenied

WriteMessages = CannotWrite FileIsTooBig FileSystemDiskBlocksQuotaExhausted LowLevelException UnexpectedWriteError

Templates =\
$(call Template,$(Container),DynamicArrayBase)\
$(call Template,$(Container),DynamicArray)\
$(call Template,$(Container),MoveDynamicArray)\
$(call Template,..,SharedPtr)\
$(call Template,$(Actions),ActionRequiringTable)\
$(call Template,$(Actions),ActionRequiringTableValue)\
$(call Template,$(Actions),ActionRequiringTableColumnAndValue)\
$(call Template,$(Actions),ActionUsingTableNameColumnAndValue)\
$(call Template,$(Actions),ActionUsingOnlyTable)\
$(call Template,$(Components),ComponentWithPolymorphicModel)\
$(call Template,$(Parsers),ParseResult)

Objects = Window BasicRenderer CenteredRenderer Centered String ConstString FixedSizeString PolymorphicModel ListModel ListComponent\
ListTablesModelAdaptor ColumnMetaData SharedPtr RowsFilterResult TableData Table Tables ListTableModelAdaptor\
OutputFile Writer fpconv TypesOutputer CharSequenceParser Action ShowTables Argument InfoModel InfoComponent\
UnknownCommand MissingArgument MissingTableName MessageContainingTableName InvalidTableName TableNotFound\
TokenException InvalidSymbolAtPosition TableNameParser ParseTableName Describe TableRenamed NoRename Rename\
NewNameIsNotUnique TableCreated TableExists CreateTable InvalidColumnType ListCommandsModelAdaptor MissingColumnType\
InvalidColumnType ColumnsLimitReached NewColumnAdded ColumnTypeParser AddColumn TableOutputerToFile MissingFileName ParseFileName\
TableSaved FileIOMessage $(OpenMessages) $(WriteMessages) Save IntegerParser ColumnNumberParser\
FractionalNumberParser StringParser ParserMessage SingleSign InvalidNumber InvalidInteger IntegerOutOfRange\
SingleFloatingPoint FractionalNumberIsMissingPart FractionalNumberHasNoIntegerPart FractionalNumberHasNoFractionalPart\
InvalidFractionalNumber FractionalNumberDigitsLimit MissingDoubleQuotesInString MissingDoubleQuotesInTheBeginning\
UnEscapedBackslashInString MissingDoubleQuotesInTheEnd WrongNumberOfColumns InsertIntoTableWithNoColumns InsertedIntoTable\
Insert ColumnNumberCannotBe ColumnNumberCannotHaveSign ColumnNumberOutOfRange InvalidColumnNumber NullColumnNumber ZeroColumnNumber\
MissingColumnNumber MissingColumnValue TableHasLessColumns RowsQueryResult CountedRows Count DeletedRows Delete\
TablePageModel TablePageComponent TableHasNoNothingToBePrinted TableHasNoColumnsNothingToBePrinted TableHasNoRowsNothingToBePrinted\
Print NoRowsSelected Select WelcomeInfo Welcome Help Quit Application 

compileAll: $(Templates) app

app: ../app/main.cc $(addsuffix .o,$(Objects))
	$(COMPILER) -pthread $^

all: stringifyIntegerLimits dependencies app

$(eval $(call Object,$(Renderer),Window))

$(eval $(call Object,$(Renderer),Centered))

$(eval $(call Object,$(Renderer),BasicRenderer))

$(eval $(call Object,$(Renderer),CenteredRenderer,BasicRenderer))

$(eval $(call Object,..,String))

$(eval $(call Object,$(String),ConstString,String))

$(eval $(call Object,$(String),FixedSizeString,String))

$(eval $(call Object,$(Components),PolymorphicModel))

$(eval $(call Object,$(List),ListModel,PolymorphicModel))

$(eval $(call Object,$(List),ListComponent,Window CenteredRenderer TypesOutputer ListModel))

$(eval $(call Object,$(Info),InfoModel,PolymorphicModel))

$(eval $(call Object,$(Info),InfoComponent,Window CenteredRenderer TypesOutputer InfoModel))

$(eval $(call Object,$(Table),ColumnMetaData))

SharedPtr.o: $(SharedPtr)/SharedPtr.cc $(SharedPtr)/SharedPtr.htd
	$(COMPILER) -c $<

$(eval $(call Object,$(TableData),RowsFilterResult))

$(eval $(call Object,$(Table),TableData,SharedPtr FixedSizeString RowsFilterResult))

$(eval $(call Object,..,Table,ColumnMetaData TableData))

$(eval $(call Object,..,Tables,Table))

$(eval $(call Object,$(ModelAdaptors),ListTablesModelAdaptor,ListModel))

$(eval $(call Object,$(ModelAdaptors),ListTableModelAdaptor,ListModel))

$(eval $(call Object,$(ModelAdaptors),ListCommandsModelAdaptor,ListModel))

$(eval $(call Object,$(Writer),OutputFile))

$(eval $(call Object,$(FileIO),Writer,OutputFile))

fpconv.o: $(fpconv)/fpconv.c $(fpconv)/fpconv.h $(fpconv)/powers.h
	$(COMPILER) -c $<

$(eval $(call Object,..,TypesOutputer,Writer SharedPtr String ConstString ColumnMetaData fpconv))

$(eval $(call Object,$(Parsers),CharSequenceParser,ConstString))

$(eval $(call Object,$(Exceptions),TokenException))

$(eval $(call Object,$(Exceptions),InvalidSymbolAtPosition,TokenException))

$(eval $(call Object,$(Parsers),TableNameParser,CharSequenceParser InvalidSymbolAtPosition))

$(eval $(call Object,$(Parsers),ColumnTypeParser,CharSequenceParser TokenException ColumnMetaData))

$(eval $(call Object,$(Action),Argument,ConstString FixedSizeString))

$(eval $(call Object,$(Messages),UnknownCommand,ConstString FixedSizeString TypesOutputer InfoModel))

$(eval $(call Object,$(Actions),Action,Tables ConstString CharSequenceParser UnknownCommand))

$(eval $(call Object,$(Actions),ShowTables,Action ListComponent))

$(eval $(call Object,$(Messages),MissingArgument,String ConstString TypesOutputer))

$(eval $(call Object,$(Messages),MissingTableName,MissingArgument))

$(eval $(call Object,$(Messages),MessageContainingTableName,String ConstString FixedSizeString TypesOutputer))

$(eval $(call Object,$(Messages),InvalidTableName,MessageContainingTableName))

$(eval $(call Object,$(Messages),TableNotFound,MessageContainingTableName))

$(eval $(call Object,$(Actions),ParseTableName,Action TableNameParser MissingTableName))

$(eval $(call Object,$(Actions),Describe,Action TableNameParser ParseTableName ListComponent ListTableModelAdaptor))

$(eval $(call Object,$(Messages),TableRenamed,String ConstString FixedSizeString TypesOutputer))

$(eval $(call Object,$(Messages),NoRename,MessageContainingTableName))

$(eval $(call Object,$(Messages),NewNameIsNotUnique,MessageContainingTableName))

$(eval $(call Object,$(Actions),Rename,Action TableNameParser ParseTableName TableRenamed NoRename NewNameIsNotUnique))

$(eval $(call Object,$(Messages),TableCreated,MessageContainingTableName))

$(eval $(call Object,$(Messages),TableExists,MessageContainingTableName))

$(eval $(call Object,$(Actions),CreateTable,Action TableNameParser ParseTableName TableCreated TableExists))

$(eval $(call Object,$(Messages),InvalidColumnType,String ConstString FixedSizeString InfoModel TypesOutputer))

$(eval $(call Object,$(Messages),MissingColumnType,String ConstString FixedSizeString InfoModel TypesOutputer))

$(eval $(call Object,$(Messages),NewColumnAdded,MessageContainingTableName))

$(eval $(call Object,$(Messages),ColumnsLimitReached,String ConstString InfoModel TypesOutputer TableData))

$(eval $(call Object,$(Actions),AddColumn,Action TableNameParser ParseTableName InvalidColumnType MissingColumnType ColumnsLimitReached NewColumnAdded ColumnMetaData))

$(eval $(call Object,$(Actions),Help,Action InfoModel ListComponent ListCommandsModelAdaptor CharSequenceParser UnknownCommand TypesOutputer))

$(eval $(call Object,$(Actions),Quit))

$(eval $(call Object,$(Table),TableOutputerToFile,ConstString Writer TypesOutputer))

$(eval $(call Object,$(Messages),MissingFileName,MissingArgument))

$(eval $(call Object,$(Messages),TableSaved,MessageContainingTableName))

$(eval $(call Object,$(Messages)/FileIO,FileIOMessage,InfoModel ConstString FixedSizeString TypesOutputer))

$(foreach message,$(OpenMessages),$(eval $(call FileIOMessage,$(message),OpenMessage)))

$(foreach message,$(WriteMessages),$(eval $(call FileIOMessage,$(message),WriteMessage)))

$(eval $(call Object,$(Actions),ParseFileName,Action MissingFileName))

$(eval $(call Object,$(Actions),Save,TableOutputerToFile MissingFileName ParseFileName\
TableSaved FileIOMessage $(OpenMessages) $(WriteMessages)))

$(eval $(call Object,$(Parsers),IntegerParser,CharSequenceParser InvalidSymbolAtPosition TokenException))

$(eval $(call Object,$(Parsers),ColumnNumberParser,IntegerParser))

$(eval $(call Object,$(Parsers),FractionalNumberParser,IntegerParser))

$(eval $(call Object,$(Parsers),StringParser,CharSequenceParser InvalidSymbolAtPosition TokenException))

$(eval $(call Object,$(Messages)/Parsers,ParserMessage,InfoModel ConstString FixedSizeString TypesOutputer))

$(eval $(call Object,$(Messages)/Parsers,SingleSign,ParserMessage))

$(eval $(call Object,$(Messages)/Parsers,InvalidNumber,ParserMessage))

$(eval $(call Object,$(Messages)/Parsers,InvalidInteger,InvalidNumber))

$(eval $(call Object,$(Messages)/Parsers,IntegerOutOfRange,ParserMessage))

$(eval $(call Object,$(Messages)/Parsers,SingleFloatingPoint,ParserMessage))

$(eval $(call Object,$(Messages)/Parsers,FractionalNumberIsMissingPart,MessageContainingTableName))

$(eval $(call Object,$(Messages)/Parsers,FractionalNumberHasNoIntegerPart,FractionalNumberIsMissingPart))

$(eval $(call Object,$(Messages)/Parsers,FractionalNumberHasNoFractionalPart,FractionalNumberIsMissingPart))

$(eval $(call Object,$(Messages)/Parsers,InvalidFractionalNumber,InvalidNumber))

$(eval $(call Object,$(Messages)/Parsers,FractionalNumberDigitsLimit,ParserMessage))

$(eval $(call Object,$(Messages)/Parsers,MissingDoubleQuotesInString,ParserMessage))

$(eval $(call Object,$(Messages)/Parsers,MissingDoubleQuotesInTheBeginning,MissingDoubleQuotesInString))

$(eval $(call Object,$(Messages)/Parsers,MissingDoubleQuotesInTheEnd,MissingDoubleQuotesInString))

$(eval $(call Object,$(Messages)/Parsers,UnEscapedBackslashInString,ParserMessage))

$(eval $(call Object,$(Messages),WrongNumberOfColumns,MessageContainingTableName Table))

$(eval $(call Object,$(Messages),InsertIntoTableWithNoColumns,MessageContainingTableName))

$(eval $(call Object,$(Messages),InsertedIntoTable,MessageContainingTableName))

$(eval $(call Object,$(Actions),Insert,SingleSign InvalidInteger IntegerOutOfRange SingleFloatingPoint\
FractionalNumberIsMissingPart FractionalNumberHasNoIntegerPart FractionalNumberHasNoFractionalPart\
FractionalNumberDigitsLimit MissingDoubleQuotesInString MissingDoubleQuotesInTheBeginning UnEscapedBackslashInString\
MissingDoubleQuotesInTheEnd WrongNumberOfColumns InsertIntoTableWithNoColumns InsertedIntoTable))

$(eval $(call Object,$(ColumnNumberParserMessages),ColumnNumberCannotBe,ConstString TypesOutputer InfoModel))

$(eval $(call Object,$(ColumnNumberParserMessages),ColumnNumberCannotHaveSign,ConstString FixedSizeString TypesOutputer InfoModel))

$(eval $(call Object,$(ColumnNumberParserMessages),ColumnNumberOutOfRange,ConstString FixedSizeString TypesOutputer InfoModel))

$(eval $(call Object,$(ColumnNumberParserMessages),InvalidColumnNumber,ConstString FixedSizeString TypesOutputer InfoModel ColumnNumberParser))

$(eval $(call Object,$(ColumnNumberParserMessages),NullColumnNumber,ColumnNumberCannotBe))

$(eval $(call Object,$(ColumnNumberParserMessages),ZeroColumnNumber,ColumnNumberCannotBe))

$(eval $(call Object,$(Messages),MissingColumnNumber,MissingArgument))

$(eval $(call Object,$(Messages),MissingColumnValue,MissingArgument))

$(eval $(call Object,$(Messages),TableHasLessColumns,MessageContainingTableName Table))

$(eval $(call Object,$(Messages),RowsQueryResult,ConstString TypesOutputer InfoModel))

$(eval $(call Object,$(Messages),CountedRows,RowsQueryResult))

ActionUsingTableNameColumnAndValueDeps = ColumnNumberCannotHaveSign ColumnNumberOutOfRange InvalidColumnNumber NullColumnNumber\
ZeroColumnNumber MissingColumnNumber MissingColumnValue TableHasLessColumns SingleSign InvalidInteger IntegerOutOfRange\
SingleFloatingPoint FractionalNumberIsMissingPart FractionalNumberHasNoIntegerPart FractionalNumberHasNoFractionalPart\
FractionalNumberDigitsLimit MissingDoubleQuotesInString MissingDoubleQuotesInTheBeginning UnEscapedBackslashInString\
MissingDoubleQuotesInTheEnd ParseTableName

$(eval $(call Object,$(Actions),Count,$(ActionUsingTableNameColumnAndValueDeps)))

$(eval $(call Object,$(Messages),DeletedRows,RowsQueryResult))

$(eval $(call Object,$(Actions),Delete,$(ActionUsingTableNameColumnAndValueDeps)))

$(eval $(call Object,$(TablePage),TablePageModel,Table))

$(eval $(call Object,$(TablePage),TablePageComponent,Window CenteredRenderer TypesOutputer TablePageModel))

$(eval $(call Object,$(Messages),TableHasNoNothingToBePrinted,MessageContainingTableName))

$(eval $(call Object,$(Messages),TableHasNoColumnsNothingToBePrinted,TableHasNoNothingToBePrinted))

$(eval $(call Object,$(Messages),TableHasNoRowsNothingToBePrinted,TableHasNoNothingToBePrinted))

$(eval $(call Object,$(Actions),Print,Action TableNameParser ParseTableName TablePageComponent\
TableHasNoColumnsNothingToBePrinted TableHasNoRowsNothingToBePrinted))

$(eval $(call Object,$(Messages),WelcomeInfo,ConstString InfoModel))

$(eval $(call Object,$(Messages),NoRowsSelected,MessageContainingTableName))

$(eval $(call Object,$(Actions),Select,Action TableNameParser ParseTableName TablePageComponent NoRowsSelected))

$(eval $(call Object,$(Actions),Welcome,Action WelcomeInfo))

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