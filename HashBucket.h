#ifndef HASHBUCKET_H
#define HASHBUCKET_H

#include "Transaction.h"

//template <typename K, typename V>
class HashBucket
{
public:
	HashBucket(const long &key, const Transaction &value)
		: key{key}, value{value}, next(nullptr)
	{ }
	
	long getKey() const;
	
	Transaction getValue() const;
	void setValue(Transaction value);
	
	HashBucket* getNext() const;
	void setNext(HashBucket* next);

private:
	long key{};
	Transaction value{};
	HashBucket* next{};
};

#endif