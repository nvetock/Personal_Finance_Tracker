#include "Transaction.h"

std::atomic_uint32_t Transaction::current_transaction_id{ 0 };

// GETTERS
const uint32_t Transaction::getTransactionId() const {
	return transaction_id;
}

const TransactionType Transaction::getTransactionType() const {
	return transaction_type;
}

const TransactionCategory Transaction::getTransactionCategory() const {
	return category;
}

const double Transaction::getAmount() const {
	return amount;
}

const std::string& Transaction::getDescription() const {
	return description;
}


// SETTERS
void Transaction::setTransactionType(TransactionType t) {
	transaction_type = t;
}

void Transaction::setTransactionCategory(TransactionCategory c) {
	category = c;
}

bool Transaction::setAmount(double amount) {
	// input validation on amount

	return false;
}

void Transaction::setDescription(std::string& msg) {
	description = msg;
}