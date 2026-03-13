#include "../include/ScalarConverter.hpp"
#include "climits"

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
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i >= literal.size())
        return false;
    
    for (; i < literal.size(); i++) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    errno = 0;
    char* endptr;
    long val = std::strtol(literal.c_str(), &endptr, 10);
    if (errno == ERANGE || *endptr != '\0')
        return false;
    if (val < INT_MIN || val > INT_MAX)
        return false;
    
    return true;
}

static bool is_float(const std::string &literal)
{
    if (literal.empty() || literal[literal.size()-1] != 'f')
        return false;
    
    std::string num = literal.substr(0, literal.size() - 1);
    if (num.empty())
        return false;
    bool has_dot = (num.find('.') != std::string::npos);
    
    if (!has_dot)
        return false;
    errno = 0;
    char* endptr;
    std::strtof(num.c_str(), &endptr);
    return (*endptr == '\0' && errno != ERANGE);
}



void print_conversions(const std::string &type, const std::string &literal)
{
    double value;

    if (type == "char")
        value = literal[1];
    else if (type == "int")
        value = std::strtol(literal.c_str(), NULL, 10);
    else if (type == "float")
    {
        std::string num = literal.substr(0, literal.size() - 1);
        value = std::strtof(num.c_str(), NULL);
    }
    else
        value = std::strtod(literal.c_str(), NULL);

    if (value >= 0 && value <= 127)
    {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: " << c << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;

    if (value >= std::numeric_limits<int>::min() &&
        value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    float f = static_cast<float>(value);

    if (f == static_cast<int>(f))
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (value == static_cast<int>(value))
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cout << "Enter valid input plz" << std::endl;
        return;
    }

    if (is_literal(literal))
    {
        special_case(literal);
        return;
    }

    if (is_char(literal))
    {
        print_conversions("char", literal);
        return;
    }

    if (is_int(literal))
    {
        print_conversions("int", literal);
        return;
    }

    if (is_float(literal))
    {
        print_conversions("float", literal);
        return;
    }
    char *endptr;
    errno = 0;
    std::strtod(literal.c_str(), &endptr);
    if (*endptr == '\0' && errno != ERANGE)
    {
        print_conversions("double", literal);
        return;
    }
    std::cout << "Enter valid input plz" << std::endl;
}