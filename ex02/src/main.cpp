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
        try
        {
            A &ref = dynamic_cast<A &>(*d);
            (void)ref;
            std::cout << "HEY" << std::endl;
        }
        catch(std::bad_cast &bd)
        {
            delete d;
            std::cout << "smth went wrong " << bd.what() << std::endl;
        }
    }
    return (0);
}