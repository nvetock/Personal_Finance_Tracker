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

const int Transaction::getDescriptionMaxLength() const {
	return description_max_length;
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
	if (std::isdigit(amount)) {
		this->amount = amount;
		return true;
	}

	return false;
}

/// <summary>
/// Sets the transaction's description. New description must be less than or equal to the max allowed length.
/// </summary>
/// <param name="msg">new description to be set</param>
/// <returns>Returns true or false based on success</returns>
bool Transaction::setDescription(std::string& msg) {
	
	if (msg.size() <= getDescriptionMaxLength()) {
		description = msg;
		return true;
	}

	return false;
}



// LOGIC

/// <summary>
/// Sets the transaction's description to an empty string.
/// </summary>
void Transaction::removeDescription() {
	description = "";
}

std::ostream& operator<<(std::ostream& out, const Transaction& t) {
	out << "Transaction ID: " << t.transaction_id << "\n"
		<< "Amount: " << t.amount << "\n"
		<< "Type: " << static_cast<int>(t.transaction_type) << "\n"
		<< "Category: " << static_cast<int>(t.category) << "\n"
		<< "Description: " << t.description;

	return out;
}