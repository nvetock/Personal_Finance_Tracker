#ifndef FINANCETRACKER_H
#define FINANCETRACKER_H

#include <vector>
#include <type_traits>

#include "HashTable.h"
#include "Transaction.h"


class FinanceTracker
{
public:

	FinanceTracker()
	{ }

	~FinanceTracker()
	{ }

	bool addTransaction();
	bool addTransaction(TransactionType type, TransactionCategory category, double amount, std::string& description);
	Transaction getTransaction(uint32_t id);
	bool removeTransaction(uint32_t id);

	template<typename... IDs>
	std::vector<Transaction> getTransactionList(IDs... ids) {
		static_assert((std::is_same_v<IDs, uint32_t> && ...),
			"All arguments must be uint32_t");
		
		std::vector result{ Transaction(ids) };



		return result;
	}

private:
	HashTable table{};



};

#endif