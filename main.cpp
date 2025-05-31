#include <iostream>
#include <string>
#include <array>
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


	std::array<int, 5> arr{};

	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i];
	}

	return 0;
}