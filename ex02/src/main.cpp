#include "Base.hpp"


int main(void)
{
    {
        std::srand(time(NULL));
        Base *c = generate();
        identify(*c);
        // Base *c = NULL;
        identify(c);
        delete c;
    }
    {
        Base *d = new B();
        A &ref = dynamic_cast<A &>(*d);
        (void)ref;
        std::cout << "HEY" << std::endl;
    }
    {
        Base &rf = * generate(); 
        identify(rf);
    }
    return (0);
}