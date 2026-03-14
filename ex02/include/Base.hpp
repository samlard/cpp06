#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>


class Base
{
    public :
        virtual ~Base();
};

class BadCastException : public std::exception {
public:
    virtual const char* what() const throw(){
        return "Bad cast happened!";
    }
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif