#ifndef HASHTAB_H
#define HASHTAB_H

#include <iostream>
#include <cmath>

typedef struct HashData{
	int key;
	struct HashData *next;
	int data;
} HashD;

class HashTab {

private:
	int size;
	int r;
	HashD *hashD;	
	int hashFunction(int key);

public:
	HashTab(int _r) :r(_r)
	{
		size = pow(2, r);
		hashD = new HashD[size];
	}

	~HashTab()
	{
		delete []hashD;
	}

	int search(int key);
	bool insert(int key, int data);
	bool remove(int key);	
};

#endif
