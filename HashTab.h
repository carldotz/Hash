#ifndef HASHTAB_H
#define HASHTAB_H

#include <iostream>
#include <cmath>

typedef struct HashData{
	long key;
	struct HashData *next;
	long data;
} HashD;

class HashTab {

private:
	long size;
	long r;
	HashD **hashD;	
	long hashFunction(long key);
	void freeLink(HashD *);

public:
	HashTab(long _r) :r(_r) {
		size = pow(2, r);
		hashD = new HashD*[size];
	}

	~HashTab() {
		for(long i=0;i<size;++i) 
			freeLink(hashD[i]->next);
		delete []hashD;
	}

	long search(long key);
	bool insert(long key, long data);
	bool remove(long key);	
};

inline long HashTab::hashFunction(long key) {
	static const long W = 32;
	static const long A = 0x9E3579B9;
	static const long F = 0x100000000;
	//cout << (key * A % (F) >> (W - r)) << endl;;
	return key * A % (F) >> (W - r);
}


#endif
