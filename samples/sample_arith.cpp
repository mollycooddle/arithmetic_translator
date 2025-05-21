#include <iostream>
#include "tarith.h"

void main()
{
    std::string strng;

    while (strng != "0") {

        try {
            std::cout << "Enter an expression (keyboard consists of digits, brackets, +, -, *, /, .):" << std::endl;
            std::cin >> strng;
            Calculator yr(strng);
            yr.stackFilling();
            yr.calculation();
            std::cout << "Result: " << yr[0] << std::endl;
        }
        catch (std::invalid_argument& er) {
            std::cout << er.what() << std::endl;
        }
    }
}
