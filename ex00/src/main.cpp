#include "../include/ScalarConverter.hpp"

int main(int ac, char **argv)
{
    if (ac == 2)
    {
        ScalarConverter::convert(argv[1]);
    }
    else
        std::cout << "only one param needed to run this program" << std::endl;
    return 0;
};
