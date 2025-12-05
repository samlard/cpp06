#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
};

ScalarConverter::~ScalarConverter(){
};

ScalarConverter::ScalarConverter(const ScalarConverter &src){
    (void)src;
};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
    (void)src;
    return *this;
};


static void special_case(const std::string &literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }

}

static bool is_literal(const std::string &literal)
{
     if (literal == "nan" || literal == "+inf" || 
        literal == "-inf" || literal == "nanf" || literal == "+inff" || literal == "-inff")
        return (true);
    return false;
}

static bool is_char(const std::string &literal)
{
    if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'' )
        return true;
    return false;
}

static bool is_int(const std::string &literal)
{
    size_t i;

    i = 0;
    while (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i == literal.size())
        return false;
    while (literal[i])
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (is_literal(literal))
        special_case(literal);
    if (literal.empty())
    {
        std::cout << "No empty string plz" << std::endl;
        return;
    }
    if (is_char(literal))
    {
        std::cout << "salut" << std::endl;
    }
    if (is_int(literal))
    {
        std::cout << "ok" << std::endl;
    }
    
};
