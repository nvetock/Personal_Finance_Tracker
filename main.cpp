#include <iostream>
#include <string>
#include <array>
#include <random>

#include "Logger.h"
#include "HashTable.h"
#include "Transaction.h"
#include "FinanceTracker.h"



int main()
{
	Logger myLogger("Logs/main.log");
	//FinanceTracker tracker{};
	
	FinanceTracker tracker{};

	std::uniform_real_distribution<double> real_num(0.00, 350.00);
	std::default_random_engine rand;

	std::string m { "empty" };


	for (int i = 0; i < 20; ++i) {
		tracker.addTransaction(TransactionType::income, TransactionCategory::food, real_num(rand), m);
	}

	std::cout << "Welcome to Finance Tracker\n\n";
	while (true) {

		std::cout << "| (1) Add Transaction |\n| (2) Get Transaction |\n| (3) List All Transactions |\n| (4) Remove Transaction |"



	}



	/*
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
	*/




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