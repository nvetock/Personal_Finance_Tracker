#pragma once

#include <string>
#include <atomic>
#include <ostream>

#include "TransactionEnum.h"

class Transaction
{


public:
	Transaction()
		:
		transaction_id{ current_transaction_id++ },
		transaction_type{ TransactionType::none },
		category{ TransactionCategory::none },
		amount{ 0.0 },
		description{ "" },
		description_max_length{ 255 }
	{
	}

	Transaction(
		TransactionType trans_type,
		TransactionCategory trans_cat,
		double amount,
		std::string& description,
		int desc_max_length=255
	)	:
		transaction_id{ current_transaction_id++ },
		transaction_type{trans_type},
		category{trans_cat},
		amount{amount},
		description{description},
		description_max_length { desc_max_length }
	{ }

	~Transaction() {}

	// GETTERS
	const uint32_t getTransactionId() const;
	const TransactionType getTransactionType() const;
	const TransactionCategory getTransactionCategory() const;
	const double getAmount() const;
	const std::string& getDescription() const;
	const int getDescriptionMaxLength() const;


	// SETTERS
	void setTransactionType(TransactionType t);
	void setTransactionCategory(TransactionCategory c);
	bool setAmount(double amount);
	bool setDescription(std::string& msg);
	void removeDescription();

	friend std::ostream& operator<<(std::ostream& out, const Transaction& t);


private:
	// Number will never be negative so uint
	uint32_t transaction_id{ 0 };
	// Atomic is used to prevent data races if written to at same time.
	static std::atomic_uint32_t current_transaction_id;


	TransactionType transaction_type{};
	TransactionCategory category{};
	double amount{ 0.0 };
	//date
	std::string description{ "" };
	int description_max_length{};
};

