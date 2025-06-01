#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <optional>

#include "HashBucket.h"

class HashTable
{
public:
	HashTable(const uint16_t table_size=11)
		: table_size{ table_size }
	{
		for (int i = 0; i < table_size; ++i) {
			HashBucket* h{ new HashBucket() };
			table.push_back(h);
		}
	}

	~HashTable() {
		for (int i = table.size() - 1; i >= 0; --i) {
			delete table[i]->getValue();
		}
	}

	// GETTERS
	const uint16_t getTableSize() const;


	// SETTERS
	void setTableSize(const uint16_t n);

	// HASH TABLE OPERATIONS
	bool insert(uint32_t key, Transaction* value);

	bool remove(uint32_t key);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="key"></param>
	/// <returns>Returns table index where matching item is located as a uint16_t positive value. Else -1.</returns>
	const Transaction* search(uint32_t key);

	// Testing Operations
	int64_t printKey(uint16_t index);

private:
	uint16_t table_size{};
	std::vector<HashBucket*> table{};


	uint32_t hashKey(uint32_t key);

	/// <summary>
	/// Resizes the current Hash Table and re-implements the values that were held in the previous table before replacing that old table.
	/// </summary>
	/// <returns>std::vector<HashBucket></returns>
	bool resize();
};

#endif