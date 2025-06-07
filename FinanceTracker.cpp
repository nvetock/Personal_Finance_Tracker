#include "FinanceTracker.h"

bool FinanceTracker::addTransaction() {
	
	Transaction t{ Transaction() };
	this->table.insert(t.getTransactionId(), &t);
	
	return true;
}

bool FinanceTracker::addTransaction(TransactionType type, TransactionCategory category, double amount, std::string& description) {
	
	if (std::isdigit(amount)) {
		Transaction t{ Transaction(type, category, amount, description) };
		this->table.insert(t.getTransactionId(), &t);

		return true;
	}

	return false;
}

const Transaction* FinanceTracker::getTransaction(uint32_t id) {

	return this->table.search(id);

}

bool FinanceTracker::removeTransaction(uint32_t id){
	
	return this->table.remove(id);

}

