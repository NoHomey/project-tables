#include "SharedPtr.htd"

SharedPtr::SharedPtr() noexcept
: deleter{nullptr}, controlBlock{nullptr} { }

SharedPtr::SharedPtr(std::nullptr_t) noexcept
: SharedPtr{} { }

SharedPtr::Counter* SharedPtr::getCounter() noexcept {
    return static_cast<Counter*>(controlBlock);
}

void SharedPtr::release() noexcept {
    if(!isNullPtr()) {
        Counter* counter = static_cast<Counter*>(controlBlock);
        Counter counterValue = *counter;
        *counter = counterValue - 1;
        if(counterValue == 1) {
            deleter(*this);
        }
    }
}

SharedPtr::~SharedPtr() noexcept {
    release();
}

void SharedPtr::acquire() noexcept {
    if(!isNullPtr()) {
        Counter* counter = getCounter();
        ++(*counter);
    }
}

SharedPtr::SharedPtr(const SharedPtr& other) noexcept
: deleter(other.deleter), controlBlock{other.controlBlock} {
    acquire();
}

void SharedPtr::set(Deleter deleter, void* controlBlock) noexcept {
    this->deleter = deleter;
    this->controlBlock = controlBlock;
}

void SharedPtr::null() noexcept {
    set(nullptr, nullptr);
}

SharedPtr& SharedPtr::operator=(const SharedPtr& other) noexcept {
    if(this != &other) {
        release();
        set(other.deleter, other.controlBlock);
        acquire();
    }
    return *this;
}

SharedPtr& SharedPtr::operator=(std::nullptr_t) noexcept {
    if(!isNullPtr()) {
        release();
        null();
    }
    return *this;
}

bool SharedPtr::operator==(const SharedPtr& other) const noexcept {
    return controlBlock == other.controlBlock;
}

bool SharedPtr::operator!=(const SharedPtr& other) const noexcept {
    return !operator==(other);
}

bool SharedPtr::isNullPtr() const noexcept {
    return controlBlock == nullptr;
}

SharedPtr::Counter SharedPtr::sharedBy() const noexcept {
    return isNullPtr() ? 0 : *const_cast<SharedPtr* const>(this)->getCounter();
}