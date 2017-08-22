#include "Save.h"
#include "../ParseTableName/ParseTableName.h"
#include "../Message/Message.h"
#include "../ParseFileName/ParseFileName.h"
#include "../../../Table/TableOutputerToFile/TableOutputerToFile.h"
#include "../../Messages/FileIO/WriterMessages.h"
#include "../../Messages/TableSaved/TableSaved.h"
#include "../../../FileIO/Writer/OutputFile/Exceptions/Exceptions.h"

Save Save:: instance;

ConstString Save::actionString{"Save"};

Save::Save() noexcept
: Base{SaveState::ParseTableName} { }

Action* Save::save() noexcept {
    instance.setState(SaveState::ParseTableName);
    return &instance;
}

Action* Save::parseTableName() {
    return Base::parseTableName<Save>(SaveState::ParseFileName, SaveState::TableNotFound);
}

Action* Save::parseFileName() {
    Action* parseAction = ParseFileName::parseFileName(actionString)->action();
    if(parseAction != nullptr) {
        return parseAction;
    }
    setState(SaveState::SaveTable);
    return this;
}

Action* Save::saveTable() {
    TableOutputerToFile outputer(*currentTable);
    ConstString& file = arguments[1].asTemporaryString();
    try {
        outputer.outputToFile(file);
    } catch(const OpenException::PermitionDenied& error) {
        return Message::showMessage(PermitionDenied::inject(file));
    } catch(const OpenException::CannotCreateFile& error) {
        return Message::showMessage(CannotCreateFile::inject(file));
    } catch(const OpenException::ItIsADirectory& error) {
        return Message::showMessage(ItIsADirectory::inject(file));
    } catch(const OpenException::FileNameIsTooLong& error) {
        return Message::showMessage(FileNameIsTooLong::inject(file));
    } catch(const OpenException::FileIsTooLarge& error) {
        return Message::showMessage(FileIsTooLarge::inject(file));
    } catch(const OpenException::FileIsSealed& error) {
        return Message::showMessage(FileIsSealed::inject(file));
    } catch(const OpenException::ReadOnlyFileSystem& error) {
        return Message::showMessage(FileIsLocatedOnReadOnlyFileSystem::inject(file));
    } catch(const OpenException::CannotOpenFile& error) {
        return Message::showMessage(CannotOpenFile::inject(file));
    } catch(const WriteException::FileSystemDiskBlocksQuotaExhausted& error) {
        return Message::showMessage(FileSystemDiskBlocksQuotaExhausted::inject(file));
    } catch(const WriteException::FileIsTooBig& error) {
        return Message::showMessage(FileIsTooBig::inject(file));
    } catch(const WriteException::CannotWrite& error) {
        return Message::showMessage(CannotWrite::inject(file));
    } catch(const WriteException::LowLevelException& error) {
        return Message::showMessage(LowLevelException::inject(file));
    } catch(const WriteException::UnexpectedWriteError& error) {
        return Message::showMessage(UnexpectedWriteError::inject(file));
    }
    return Message::showMessage(TableSaved::inject(currentTable->getName(), file));
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
