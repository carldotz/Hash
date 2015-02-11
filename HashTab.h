#ifndef HASHTAB_H
#define HASHTAB_H

#include <iostream>
#include <cmath>

template <typename T>
struct HashData {
	long key;
	HashData<T> *next;
	T data;
};

template <typename T>
class HashTab {

private:
	long size;
	long r;
	HashData<T> **hashD;	
	long hashFunction(long key);
	void freeLink(HashData<T> *);

public:
	HashTab(long _r) :r(_r) {
		size = pow(2, r);
		hashD = new HashData<T>*[size];
	}

	~HashTab() {
		for(long i=0;i<size;++i) 
			freeLink(hashD[i]->next);
		delete []hashD;
	}

	T search(long key);
	bool insert(long key, T data);
	bool remove(long key);	
};

template <typename T>
inline long HashTab<T>::hashFunction(long key) {
	static const long W = 32;
	static const long A = 0x9E3579B9;//2^32 * 0.61803398
	static const long F = 0x100000000;//2^32
	//cout << (key * A % (F) >> (W - r)) << endl;;
	return key * A % (F) >> (W - r);
}

template <typename T>
T HashTab<T>::search(long key) {
	long position = hashFunction(key);
	
	HashData<T> * currentHashData = *(hashD + position);

	while(currentHashData != NULL) {
		if(currentHashData->key == key) {
			return currentHashData->data;
		}
		currentHashData = currentHashData->next;
	}

	std::cout << "Have Not found " << key << std::endl;

	return 0;
}

template <typename T>
bool HashTab<T>::remove(long key) {
	long position = hashFunction(key);
	
	HashData<T> * currentHashData = *(hashD + position);
	HashData<T> * preHashData = *(hashD + position);

	while(currentHashData != NULL) {
		if(currentHashData->key == key) {
			if(currentHashData == preHashData) {
				hashD[position] = currentHashData->next;
			} else {
				preHashData->next = currentHashData->next;
			}
			delete currentHashData;
			return true;
		}
		preHashData = currentHashData;
		currentHashData = currentHashData->next;
	}

	std::cout << "Have Not found " << key << std::endl;

	return false;
}

template <typename T>
bool HashTab<T>::insert(long key, T data) {
	
	long position = hashFunction(key);

	HashData<T> * currentHashData = *(hashD + position);

	if(currentHashData == NULL) {

			hashD[position] = new HashData<T>;
			hashD[position]->key = key;
			hashD[position]->data = data;
			hashD[position]->next = NULL;

	} else {

		while(currentHashData->next != NULL) {
			if(currentHashData->key == key) {
				std::cout << "Insert Error: Key=" << 
						key << std::endl;
				return false;
			}
			currentHashData = currentHashData->next;
		}
		currentHashData->next = new HashData<T>;
		currentHashData = currentHashData->next;
		currentHashData->key = key;
		currentHashData->data = data;
		currentHashData->next = NULL;
	}
	
	return true;
}

template <typename T>
void HashTab<T>::freeLink(HashData<T> *point) {
	
	if(point != NULL) {
		freeLink(point->next);
	}
	delete point;
}
#endif
