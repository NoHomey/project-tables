#include "Save.h"
#include "../ParseFileName/ParseFileName.h"
#include "../../../Table/TableOutputerToFile/TableOutputerToFile.h"
#include "../../Messages/FileIO/WriterMessages.h"
#include "../../Messages/TableSaved/TableSaved.h"
#include "../../../FileIO/Writer/OutputFile/Exceptions/Exceptions.h"

Save Save::instance;

ConstString Save::actionString{"Save"};

ConstString Save::description{"Command usage: 'Save <Table> <Path to file>'. Command description: Saves Table with name <Table> to file with path <Path to file>."};

Save::Save() noexcept
: Base{SaveState::ParseTableName} { }

Action* Save::controller() noexcept {
    return &instance;
}

Action* Save::parseTableName() {
    return Base::parseTableName<Save>(SaveState::ParseFileName, SaveState::TableNotFound);
}

Action* Save::parseFileName() {
    if(ParseFileName::parseFileName(actionString)) {
        setState(SaveState::SaveTable);
        return this;
    }
    return nullptr;
}

Action* Save::saveTable() {
    TableOutputerToFile outputer(*currentTable);
    ConstString& file = arguments[1].asTemporaryString();
    try {
        outputer.outputToFile(file);
    } catch(const OpenException::PermitionDenied& error) {
        return showMessage(new PermitionDenied(file));
    } catch(const OpenException::CannotCreateFile& error) {
        return showMessage(new CannotCreateFile(file));
    } catch(const OpenException::ItIsADirectory& error) {
        return showMessage(new ItIsADirectory(file));
    } catch(const OpenException::FileNameIsTooLong& error) {
        return showMessage(new FileNameIsTooLong(file));
    } catch(const OpenException::FileIsTooLarge& error) {
        return showMessage(new FileIsTooLarge(file));
    } catch(const OpenException::FileIsSealed& error) {
        return showMessage(new FileIsSealed(file));
    } catch(const OpenException::ReadOnlyFileSystem& error) {
        return showMessage(new FileIsLocatedOnReadOnlyFileSystem(file));
    } catch(const OpenException::CannotOpenFile& error) {
        return showMessage(new CannotOpenFile(file));
    } catch(const WriteException::FileSystemDiskBlocksQuotaExhausted& error) {
        return showMessage(new FileSystemDiskBlocksQuotaExhausted(file));
    } catch(const WriteException::FileIsTooBig& error) {
        return showMessage(new FileIsTooBig(file));
    } catch(const WriteException::CannotWrite& error) {
        return showMessage(new CannotWrite(file));
    } catch(const WriteException::LowLevelException& error) {
        return showMessage(new LowLevelException(file));
    } catch(const WriteException::UnexpectedWriteError& error) {
        return showMessage(new UnexpectedWriteError(file));
    }
    return showMessage(new TableSaved(currentTable->getName(), file));
}

Action* Save::action() {
    switch(getState()) {
        case SaveState::ParseTableName: return parseTableName();
        case SaveState::TableNotFound: return tableNotFound();
        case SaveState::ParseFileName: return parseFileName();
        case SaveState::SaveTable: return saveTable();
        default: return nullptr;
    }
}

Action* Save::controlAction() noexcept {
    setState(SaveState::ParseTableName);
    return this;
}