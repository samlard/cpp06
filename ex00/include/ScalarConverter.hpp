#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter {

    public :
        static void convert(const std::string &literal);

    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);
};


#endif