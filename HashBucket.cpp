#include "HashBucket.h"

int64_t HashBucket::getKey() const {
	return key;
}

void HashBucket::setKey(const uint32_t key) {
	this->key = key;
}

const BucketAvail HashBucket::getAvailable() const {
	return availability;
}

void HashBucket::setAvailable(const BucketAvail avail) {
	availability = avail;
}

const Transaction* HashBucket::getValue() const {
	return value;
}

void HashBucket::setValue(Transaction* value) {
	this->value = value;
}


//const HashBucket* HashBucket::getNext() const {
//	return next;
//}
//
//void HashBucket::setNext(HashBucket* next) {
//	this->next = next;
//}