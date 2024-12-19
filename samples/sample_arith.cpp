#include <iostream>
#include "tarith.h"

void main()
{
    std::string strng;

    int f = 0;
    while (f == 0) {

        if (strng == "0")
            return;

        try {
            std::cout << "Enter an expression with *, /, +, -, (), float/int numbers(write 0 to complete):" << std::endl;
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
