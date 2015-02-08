#ifndef HASHTAB_H
#define HASHTAB_H

#include <iostream>

typedef struct HashData{
	int key;
	struct HashData *next;
	int data;
} HashD;

class HashTab {
private:
	int size;
	
	int hashFunction(int key);
public:
	

};

#endif
