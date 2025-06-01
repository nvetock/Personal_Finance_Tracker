#ifndef HASHBUCKET_H
#define HASHBUCKET_H

#include <iostream>
#include "Transaction.h"

enum class BucketAvail {
	empty,
	occupied,
	deleted
};

//template <typename K, typename V>
class HashBucket
{
public:
	//HashBucket()
	//{ }

	HashBucket()
		: key{ -1 }, availability{BucketAvail::empty}, value { nullptr } {

	}

	HashBucket(const uint32_t &key, const Transaction* value)
		: key{ key }, value{ value }, availability{BucketAvail::empty}
	{ }

	~HashBucket() {}
	
	int64_t getKey() const;
	void setKey(const uint32_t key);

	const BucketAvail getAvailable() const;
	void setAvailable(const BucketAvail avail);

	const Transaction* getValue() const;
	void setValue(Transaction* value);
	
	//const HashBucket* getNext() const;
	//void setNext(HashBucket* next);

private:
	int64_t key{};
	BucketAvail availability{};
	const Transaction* value{nullptr};
	//HashBucket* next{};
};

#endif