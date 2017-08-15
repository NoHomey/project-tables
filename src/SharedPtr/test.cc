#include "SharedPtr.htd"
#include "../Container/DynamicArray/DynamicArray.htd"
#include "../String/FixedSizeString/FixedSizeString.h"
#include <iostream>

void stringDeleter(SharedPtr& ptr) noexcept {
    ptr.release<FixedSizeString>();
}

int main() {
    SharedPtr own{FixedSizeString{"Nemo"}, stringDeleter};

    DynamicArray<SharedPtr> array{3};

    array.push(own);
    array.push(own);
    array.push(own);

    std::cout << own.getConstRef<FixedSizeString>()[0] << std::endl;

    std::cout << array[0].getConstRef<FixedSizeString>()[1] << std::endl;
    std::cout << array[1].getConstRef<FixedSizeString>()[2] << std::endl;
    std::cout << array[2].getConstRef<FixedSizeString>()[3] << std::endl;

    std::cout << (array[2] == own) << std::endl;

    array.setElement(2, {});
    array.setElement(1, nullptr);

    std::cout << (array[2] == own) << array[2].isNullPtr() << std::endl;
    std::cout << (array[1] == own) << array[1].isNullPtr() << std::endl;
    std::cout << (array[0] == own) << array[0].isNullPtr() << std::endl;

    std::cout << sizeof(SharedPtr) << std::endl;

    return 0;
}