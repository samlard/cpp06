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
    if (i == literal.size() || i > 1)
        return false;
    while (literal[i])
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

static bool is_float(const std::string &literal)
{
    size_t i = 0;
    size_t pos = 0;

    pos = literal.find('.', pos);
    if (pos == std::string::npos)
        return false;
    if (literal[literal.size()-1] != 'f')
        return false;
    while (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i == literal.size() || i > 1)
        return false;
    while (i < pos)
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    i++;
    while (i < literal.size() - 1)
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

static bool is_double(const std::string &literal)
{
    size_t i = 0;
    size_t pos = 0;

    pos = literal.find('.', pos);
    if (pos == std::string::npos)
        return false;
    while (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i == literal.size() || i > 1)
        return false;
    while (i < pos)
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    i++;
    while (i < literal.size())
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}


void print_conversions(const std::string &type, const std::string &literal)
{
    if (type == "char")
    {
        char c = literal[1];
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) 
                  << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) 
                  << static_cast<double>(c) << std::endl;
    }
    else if (type == "int")
    {
        int n = std::atoi(literal.c_str());
        if (n >= 32 && n <= 126)
            std::cout << "char: " << static_cast<char>(n) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << n << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) 
                  << static_cast<float>(n) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) 
                  << static_cast<double>(n) << std::endl;
    }
    else if (type == "float")
    {
        float f = std::strtof(literal.c_str(), NULL);
        
        if (f >= 32 && f <= 126)
            std::cout << "char: " << static_cast<char>(f) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
            
        if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        
        if (f == static_cast<int>(f) && f >= std::numeric_limits<int>::min() 
            && f <= std::numeric_limits<int>::max())
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
        
        double d = static_cast<double>(f);
        if (d == static_cast<int>(d) && d >= std::numeric_limits<int>::min() 
            && d <= std::numeric_limits<int>::max())
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    else if (type == "double")
    {
        double d = std::strtod(literal.c_str(), NULL);
        
        if (d >= 32 && d <= 126)
            std::cout << "char: " << static_cast<char>(d) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
            
        if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        float f_cast = static_cast<float>(d);
        if (f_cast == static_cast<int>(f_cast) && f_cast >= std::numeric_limits<int>::min() 
            && f_cast <= std::numeric_limits<int>::max())
            std::cout << "float: " << std::fixed << std::setprecision(1) << f_cast << "f" << std::endl;
        else
            std::cout << "float: " << f_cast << "f" << std::endl;
        if (d == static_cast<int>(d) && d >= std::numeric_limits<int>::min() 
            && d <= std::numeric_limits<int>::max())
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cout << "No empty string plz" << std::endl;
        return;
    }
    if (is_literal(literal))
        special_case(literal);
    else if (is_char(literal))
        print_conversions("char", literal);
    else if (is_int(literal))
        print_conversions("int", literal);
    else if (is_float(literal))
        print_conversions("float", literal);
    else if (is_double(literal))
        print_conversions("double", literal);
    else
        std::cout << "Enter valid input plz" << std::endl;
};
