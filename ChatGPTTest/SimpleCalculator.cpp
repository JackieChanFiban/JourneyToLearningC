#include <iostream>
#include <cmath>

char op;
int number1;
int number2;

int main()
{
std::cout << "Firt number here: ";
std::cin >> number1;

std::cout << "Second number here: ";
std::cin >> number2;

std::cout << "pick the operator here: ";
std::cin >> op;

int result;
if (op == '+') {
	result = number1 + number2;
	std::cout << "Result: " << result << std::endl;
}
else if (op == '-') { // Fixed the syntax error here
	result = number1 - number2;
	std::cout << "Result: " << result << std::endl;
}
else if (op == '*') {
	result = number1 * number2;
	std::cout << "Result: " << result << std::endl;
}
else if (op == '/') {
	result = number1 / number2;
	std::cout << "Result: " << result << std::endl;
}
else {
	std::cout << "Invalid operator!" << std::endl;
}

return result;
}