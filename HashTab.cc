#include "HashTab.h"

int HashTab::search(int key) {

	return key;
}

bool HashTab::insert(int key, int data) {
	long point = hashFunction(key);
	hashD[point].key = key;
	hashD[point].data = data;
	hashD[point].next = NULL;
	return true;
}

bool HashTab::remove(int key) {

	return true;
}

int HashTab::hashFunction(int key) {
	static const int W = 64;
	static const long A = (2^W) * 0.6180339887;
	int result;
	result = key * A % (2^W) >> (W - r);
	return 0;
}
