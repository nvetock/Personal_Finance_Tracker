#include <iostream>
#include <string>
#include "Logger.h"

int main()
{
	Logger myLogger("Logs/main.log");
	//FinanceTracker tracker{};
	


	int x{ 5 };

	const int *xRef = &x;

	int& d{ x };


	std::cout << x << std::endl;
	std::cout << xRef << std::endl;
	std::cout << d << std::endl;
	
	d += 1;

	std::cout << x << std::endl;
	std::cout << *xRef << std::endl;
	std::cout << d << std::endl;

	return 0;
}