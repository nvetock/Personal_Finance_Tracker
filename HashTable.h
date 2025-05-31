#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include "HashBucket.h"

class HashTable
{
public:
	HashTable(const int table_size=11)
		: table_size{ table_size }
	{ }

	// GETTERS
	const uint16_t getTableSize() const {
		return table_size;
	}


	// SETTERS
	void setTableSize(uint16_t n) {
		table_size = n;
	}

	// HASH TABLE OPERATIONS

private:
	uint16_t table_size{};
	std::vector<HashBucket> table{};

	/// <summary>
	/// Resizes the current Hash Table and re-implements the values that were held in the previous table before replacing that old table.
	/// </summary>
	/// <returns>std::vector<HashBucket></returns>
	bool resize() {
		
		// only double table size for now instead of returning next prime number
		setTableSize(table_size * 2);

		std::vector<HashBucket> temp_arr{};
		for (int i = 0; i < table.size(); ++i) {
			uint32_t k = table[i].getValue().getTransactionId();
		}

	}

	long hashKey(long key) {
		return key % table_size;
	}
};

#endif