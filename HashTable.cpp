#include "HashTable.h"



// GETTERS
const uint16_t HashTable::getTableSize() const {
	return table_size;
}


// SETTERS
void HashTable::setTableSize(const uint16_t n) {
	table_size = n;
}

// HASH TABLE OPERATIONS
bool HashTable::insert(uint32_t key, Transaction* value) {

	uint32_t bucket_index = hashKey(key);

	if (table[bucket_index]->getAvailable() == BucketAvail::empty ||
		table[bucket_index]->getAvailable() == BucketAvail::deleted) {

		table[bucket_index]->setValue(value);
		table[bucket_index]->setKey(key);
		table[bucket_index]->setAvailable(BucketAvail::occupied);

		return true;
	}
	else {
		uint32_t end_index = bucket_index;

		do {
			bucket_index = (bucket_index + 1) % table.size();
			continue;
		} while (table[bucket_index]->getAvailable() == BucketAvail::occupied &&
			bucket_index != end_index);

		if (bucket_index == end_index) {
			return false;
		}

		table[bucket_index]->setValue(value);
		table[bucket_index]->setKey(key);
		table[bucket_index]->setAvailable(BucketAvail::occupied);
		return true;
	}
}

bool HashTable::remove(uint32_t key) {

	uint32_t bucket_index = hashKey(key);

	uint32_t curr_bucket = 0;

	do {
		if (table[curr_bucket]->getKey() == key && table[curr_bucket]->getAvailable() == BucketAvail::occupied) {
			const Transaction* temp_obj = table[curr_bucket]->getValue();
			table[curr_bucket]->setKey(-1);
			table[curr_bucket]->setValue(nullptr);
			table[curr_bucket]->setAvailable(BucketAvail::deleted);

			delete temp_obj;
			return true;
		}

		++curr_bucket;
	} while (curr_bucket != table.size());

	return false;
}

const Transaction* HashTable::search(uint32_t key) {

	uint32_t bucket_index = hashKey(key);

	uint32_t end_index = bucket_index;

	do {
		if (table[bucket_index]->getKey() == key && table[bucket_index]->getAvailable() == BucketAvail::occupied) {
			return table[bucket_index]->getValue();
		}

		bucket_index = (bucket_index + 1) % table.size();

	} while (bucket_index != end_index);

	return nullptr;
}

// Testing Operations
int64_t HashTable::printKey(uint16_t index) {
	return table[index]->getKey();
}


uint32_t HashTable::hashKey(uint32_t key) {
	return key % table_size;
}

bool HashTable::resize() {

	// only double table size for now instead of returning next prime number
	setTableSize(table_size * 2);

	std::vector<HashBucket> temp_arr{};
	for (int i = 0; i < table.size(); ++i) {
		uint32_t k = table[i]->getValue()->getTransactionId();

		return true;
	}
	return false;
}