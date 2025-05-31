#pragma once

#include <string>
#include <atomic>

#include "TransactionEnum.h"

class Transaction
{


public:
	Transaction()
		: transaction_id{current_transaction_id++}
	{
	}

	Transaction(TransactionType trans_type, TransactionCategory trans_cat, double amount, std::string& description)
		: transaction_id{ current_transaction_id++ },
		transaction_type{trans_type},
		category{trans_cat},
		amount{amount},
		description{description}
	{ }

	~Transaction() {}

	// GETTERS
	const uint32_t getTransactionId() const {
		return transaction_id;
	}

	const TransactionType getTransactionType() const {
		return transaction_type;
	}

	const TransactionCategory getTransactionCategory() const {
		return category;
	}

	const double getAmount() const {
		return amount;
	}

	const std::string& getDescription() const {
		return description;
	}


	// SETTERS
	void setTransactionType(TransactionType t) {
		transaction_type = t;
	}

	void setTransactionCategory(TransactionCategory c) {
		category = c;
	}

	bool setAmount(double amount) {
		// input validation on amount

		return false;
	}

	void setDescription(string& msg) {
		description = msg;
	}

private:
	// Number will never be negative so uint
	uint32_t transaction_id{};
	// Atomic is used to prevent data races if written to at same time.
	static std::atomic_uint32_t current_transaction_id;


	TransactionType transaction_type{};
	TransactionCategory category{};
	double amount{ 0.0 };
	//date
	std::string description{ "" };

};

