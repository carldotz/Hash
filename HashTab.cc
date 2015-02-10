#include <cmath>
#include "HashTab.h"

using std::cout;
using std::endl;

long HashTab::search(long key) {
	long position = hashFunction(key);
	
	HashD * currentHashD = *(hashD + position);

	while(currentHashD != NULL) {
		if(currentHashD->key == key) {
			return currentHashD->data;
		}
		currentHashD = currentHashD->next;
	}

	cout << "Have Not found " << key << endl;

	return 0;
}

//TODO remove

bool HashTab::remove(long key) {
	long position = hashFunction(key);
	
	HashD * currentHashD = *(hashD + position);
	HashD * preHashD = *(hashD + position);

	while(currentHashD != NULL) {
		if(currentHashD->key == key) {
			if(currentHashD == preHashD) {
				hashD[position] = currentHashD->next;
			} else {
				preHashD->next = currentHashD->next;
			}
			delete currentHashD;
			return true;
		}
		preHashD = currentHashD;
		currentHashD = currentHashD->next;
	}

	cout << "Have Not found " << key << endl;

	return false;
}

bool HashTab::insert(long key, long data) {
	
	long position = hashFunction(key);

	HashD * currentHashD = *(hashD + position);

	if(currentHashD == NULL) {

			hashD[position] = new HashD;
			hashD[position]->key = key;
			hashD[position]->data = data;
			hashD[position]->next = NULL;

	} else {

		while(currentHashD->next != NULL) {
			if(currentHashD->key == key) {
				cout << "Insert Error: Key=" << 
						key << endl;
				return false;
			}
			currentHashD = currentHashD->next;
		}
		currentHashD->next = new HashD;
		currentHashD = currentHashD->next;
		currentHashD->key = key;
		currentHashD->data = data;
		currentHashD->next = NULL;
	}
	


	return true;
}

void HashTab::freeLink(HashD *point) {
	
	if(point != NULL) {
		freeLink(point->next);
	}
	delete point;
}

