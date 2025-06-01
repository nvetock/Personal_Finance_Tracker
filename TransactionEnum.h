#ifndef TRANSACTION_ENUM_H
#define TRANSACTION_ENUM_H

enum class TransactionType {
	none,
	income,
	expense
};

enum class TransactionCategory {
	none,
	rent,
	food,
	gas,
	entertainment
};

#endif