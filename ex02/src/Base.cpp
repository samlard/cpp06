#include "Base.hpp"

Base::~Base(){}

Base * generate(void)
{
    switch( std::rand() % 3)
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
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "Ref object is type A" << std::endl;
        (void)a;
        return;
    }
    catch (std::bad_cast &bd){}
    try
    {
        B &b = dynamic_cast<B &>(p);
        std::cout << "Ref object is type B" << std::endl;
        (void)b;
        return;
    }
    catch(std::bad_cast &bd){}
    try
    {
        C &c = dynamic_cast<C &>(p);
        std::cout << "Ref object is type C" << std::endl;
        (void)c;
        return;
    }
    catch(std::bad_cast &bd)
    {
    }
    
}