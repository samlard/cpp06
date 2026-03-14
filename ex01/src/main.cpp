#include <iostream>
#include "Serializer.hpp"
#include "data.hpp"

int main()
{
    // Serializer s;
    Data d;
    d.id = 123;

    std::cout << "Original Data pointer: " << &d << std::endl;
    std::cout << "Original Data id: " << d.id << std::endl;

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    Data* ptrBack = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << ptrBack << std::endl;
    std::cout << "Deserialized Data id: " << ptrBack->id << std::endl;
    if (ptrBack == &d)
        std::cout << "Success: deserialized pointer matches original!" << std::endl;
    else
        std::cout << "Error: pointers do not match." << std::endl;
    {
        uintptr_t fake = 12345678;
        Data* ptr = Serializer::deserialize(fake);
        std::cout << ptr->id;
    }
    return 0;
}
