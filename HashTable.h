#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include "HashBucket.h"
#include <optional>

class HashTable
{
public:
	HashTable(const int table_size=11)
		: table_size{ table_size }
	{
		for (int i = 0; i < table_size; ++i) {
			table[i] = new HashBucket();
		}
	}

	// GETTERS
	const uint16_t getTableSize() const {
		return table_size;
	}


	// SETTERS
	void setTableSize(const uint16_t n) {
		table_size = n;
	}

	// HASH TABLE OPERATIONS
	bool insert(uint32_t key, Transaction value) {

		uint32_t bucket_index = hashKey(key);

		if (table[bucket_index]->getAvailable() == BucketAvail::empty ||
			table[bucket_index]->getAvailable() == BucketAvail::deleted) {
			
			table[bucket_index]->setValue(&value);
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

			table[bucket_index]->setValue(&value);
			table[bucket_index]->setKey(key);
			table[bucket_index]->setAvailable(BucketAvail::occupied);
			return true;
		}
	}

	bool remove(uint32_t key) {

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

	/// <summary>
	/// 
	/// </summary>
	/// <param name="key"></param>
	/// <returns>Returns table index where matching item is located as a uint16_t positive value. Else -1.</returns>
	const Transaction* search(uint32_t key) {

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


private:
	uint16_t table_size{};
	std::vector<HashBucket*> table{};


	uint32_t hashKey(uint32_t key) {
		return key % table_size;
	}

	/// <summary>
	/// Resizes the current Hash Table and re-implements the values that were held in the previous table before replacing that old table.
	/// </summary>
	/// <returns>std::vector<HashBucket></returns>
	bool resize() {
		
		// only double table size for now instead of returning next prime number
		setTableSize(table_size * 2);

		std::vector<HashBucket> temp_arr{};
		for (int i = 0; i < table.size(); ++i) {
			uint32_t k = table[i]->getValue()->getTransactionId();


		}

	}
};

#endif