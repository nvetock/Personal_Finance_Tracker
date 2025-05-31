#include "HashBucket.h"

long HashBucket::getKey() const {
	return key;
}


Transaction HashBucket::getValue() const {
	return value;
}

void HashBucket::setValue(Transaction value) {
	HashBucket::value = value;
}


HashBucket* HashBucket::getNext() const {
	return next;
}

void HashBucket::setNext(HashBucket* next) {
	HashBucket::next = next;
}