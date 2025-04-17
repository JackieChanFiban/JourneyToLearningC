#include <iostream>

void OddorEven()
{
    int number;
    std::cout << "Pick a number: ";
    std::cin >> number;

    if (number % 2 == 0) {
        std::cout << "The number is even." << std::endl;
    }
    else {
        std::cout << "The number is odd." << std::endl;
    }
}

int main()
{
    OddorEven();
    return 0;
}
