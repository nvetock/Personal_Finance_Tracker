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

		std::cout << "| (1) Add Transaction |\n| (2) Get Transaction |\n| (3) List All Transactions |\n| (4) Remove Transaction |\n| q to quit\n\nEnter Command: ";

		std::string user_input{""};
		std::cin >> user_input;
		int num_input{ 0 };


		if (user_input == "q" || user_input == "Q") {
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else {
			num_input = stoi(user_input);
		}

		while (true) {

			if (num_input == 1) {
				std::cout << "\n\nAdd Transaction Mode:\nIncome(1) or Expense(2)?\n";
				std::cin >> user_input;
				int trans_type{ stoi(user_input) };

				std::cout << "\nCategory type?\nRent(1) | Food(2) | Gas(3) | Entertainment(4)\n";
				std::cin >> user_input;
				int trans_cat{ stoi(user_input) };

				std::cout << "\nAmount?\n";
				std::cin >> user_input;
				double amt{ stod(user_input) };

				std::cout << "\nTransaction description?\n";
				std::cin >> user_input;

				tracker.addTransaction(static_cast<TransactionType>(trans_type), static_cast<TransactionCategory>(trans_cat), amt, user_input);
				
				break;
			}
			else if (num_input == 2) {
				std::cout << "Enter Transactioin ID number:\n";
				std::cin >> user_input;
				int trans_id{ stoi(user_input) };
				const Transaction* t{ tracker.getTransaction(trans_id) };

				std::cout << t;

				break;
			}
			else if (num_input == 3) {
				const std::vector<const Transaction*> allTransactions{ tracker.getTransactionList() };

				for (int i = 0; i < allTransactions.size(); ++i) {
					std::cout << allTransactions[i] << '\n';
				}

				break;
			}
			else if (num_input == 4) {

				std::cout << "Enter Transactioin ID number to remove:\n";
				std::cin >> user_input;
				int trans_id{ stoi(user_input) };

				if (tracker.removeTransaction(trans_id)) {
					std::cout << "removed transaction #" << user_input << '\n';
				}
				std::cout << "failed to remove transaction #" << user_input << '\n';

				break;
			}
			else {
				std::cout << "Invalid input." << std::endl;
				continue;
			}
		}
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