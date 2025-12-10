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


// void print_conversions(const std::string &type, const std::string &literal)
// {

//         if (type == "char")
//         {
//             char c = literal[1];
//             std::cout << "char: " << c << std::endl;
//             std::cout << "int: " << static_cast<int>(c) << std::endl;
//             std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
//             std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
//         }
//         else if (type == "int")
//         {
//             int n = std::atoi(literal.c_str());
//             if (n >= 32 && n <= 126)
//                 std::cout << "char: " << static_cast<char>(n) << std::endl;
//             else
//             std::cout << "char: Non displayable" << std::endl;
//         std::cout << "int: " << n << std::endl;
//         std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
//         std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
//         }
//         else if (type == "float")
//         {
//             float f = std::strtof(literal.c_str(), NULL);

//             if (f >= 32 && f <= 126)
//                 std::cout << "char: " << static_cast<char>(f) << std::endl;
//             else
//                 std::cout << "char: impossible" << std::endl;

//         if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
//             std::cout << "int: " << static_cast<int>(f) << std::endl;
//         else
//             std::cout << "int: impossible" << std::endl;
//         std::cout << "float: " << f << "f" << std::endl;
//         std::cout << "double: " << static_cast<double>(f) << std::endl;
//     }
//     else if (type == "double")
//     {
//         double d = std::strtod(literal.c_str(), NULL);

//         if (d >= 32 && d <= 126)
//             std::cout << "char: " << static_cast<char>(d) << std::endl;
//         else
//             std::cout << "char: impossible" << std::endl;

//         if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
//             std::cout << "int: " << static_cast<int>(d) << std::endl;
//         else
//             std::cout << "int: impossible" << std::endl;

//         std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
//         std::cout << "double: " << d << std::endl;
//     }
// }
// // }