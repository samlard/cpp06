#include "Base.hpp"


int main(void)
{
    {
        std::srand(time(NULL));
        Base *c = generate();
        // Base *c = NULL;
        identify(*c);
        identify(c);
        delete c;
        std::cout << "============================" << std::endl;
    }
    {
        Base &d = * new C;
        identify(d);
        std::cout << "HEY" << std::endl;
        delete &d;
        std::cout << "============================" << std::endl;
    }
    {
        Base &rf = * generate();
        identify(rf);
        delete &rf;
        std::cout << "============================" << std::endl;
    }
    return (0);
}