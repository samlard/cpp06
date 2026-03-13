#include "Base.hpp"

Base::~Base(){}

Base * generate(void)
{
    switch(std::rand() % 3)
    {
        case 0 : return new A();
        case 1 : return new B();
        default : return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Pointer object Base is type A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Pointer object Base is type B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Pointer object Base is type C" << std::endl;
    else 
        std::cout << "No good type found" << std::endl;
}

void identify(Base& p)
{
//     if (dynamic_cast<A*>(&p))
//         std::cout << "Ref object has type A" << std::endl;
//     else if (dynamic_cast<B*>(&p))
//         std::cout << "Ref object has type  B" << std::endl;
//     else if (dynamic_cast<C*>(&p))
//         std::cout << "Ref object has type  C" << std::endl;
//     else 
//         std::cout << "bad cast" << std::endl;
// }
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "Ref object is type A" << std::endl;
        return;
    }
    catch (std::exception &e){
       // std::cout << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "Ref object is type B" << std::endl;
        return;
    }
    catch(std::exception &e){
      //  std::cout << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<C &>(p);
       std::cout << "Ref object is type C" << std::endl;
        return;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
    