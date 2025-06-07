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
	const Transaction* getTransaction(uint32_t id);
	bool removeTransaction(uint32_t id);

	const std::vector<const Transaction*> getTransactionList() {
		std::vector<const Transaction*> result{};

		for (int i = 0; i < table.getTableSize(); ++i) {
			if (this->table.getBucketAvailability(i)) {
				result.push_back(this->table.search(i));
			}
		}

		return result;
	}

	template<typename... IDs>
	std::vector<Transaction*> getTransactionList(IDs... ids) {
		static_assert((std::is_same_v<IDs, uint32_t> && ...),
			"All arguments must be uint32_t");
		
		std::vector result{ Transaction(ids) };



		return result;
	}

private:
	HashTable table{};



};

#endif