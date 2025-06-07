#include <iostream>
#include <string>
#include <array>

#include "Logger.h"
#include "HashTable.h"
#include "Transaction.h"

int main()
{
	Logger myLogger("Logs/main.log");
	//FinanceTracker tracker{};
	
	HashTable hashtable = HashTable();

	for (int i = 0; i < hashtable.getTableSize(); ++i) {
		std::cout << hashtable.printKey(i) << '\n';
	}
	std::string msg = "weekly gas";
	Transaction* t1 = new Transaction(TransactionType::income, TransactionCategory::gas, 40.00, msg);

	hashtable.insert(t1->getTransactionId(), t1);

	for (int i = 0; i < hashtable.getTableSize(); ++i) {
		std::cout << hashtable.printKey(i) << '\n';
	}


	const Transaction* x{ hashtable.search(t1->getTransactionId()) };
	
	std::cout << x->getAmount() << '\t' << x->getTransactionId() << '\t' << x->getDescription() << '\t' << '\n';
	/*
	* 
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
	*/

	return 0;
}