#include <iostream>
#include "HashTab.h"

using std::cout;
using std::endl;

int main() {
	HashTab<int> ht(10);

	cout << "\n********Insert*******" << endl;
	
	for(long i=0;i<10000;i++) {
		ht.insert(i, 2 * i);
	}

	cout << "\n********Search*******" << endl;

	for(long i=0;i<1000;i++) {
		for(long j=0;j<10;j++) {
			cout << ht.search(i*10 + j) << "\t";
		}
		cout << endl;
	}
	cout << "\n*********Remove******" << endl;

	ht.remove(100);
	ht.remove(500);
	ht.remove(1000);
	ht.remove(5000);
	ht.remove(9999);

	cout << "\n*********Research****" << endl;

	for(long i=0;i<1000;i++) {
		for(long j=0;j<10;j++) {
			cout << ht.search(i*10 + j) << "\t";
		}
		cout << endl;
	}

	cout << "\n*********Reinsert*******" << endl;

	ht.insert(100, 300);
	ht.insert(500, 1500);
	ht.insert(1000, 3000);
	ht.insert(5000, 15000);
	ht.insert(9999, 29997);

	cout << "\n*********Research****" << endl;

	for(long i=0;i<1000;i++) {
		for(long j=0;j<10;j++) {
			cout << ht.search(i*10 + j) << "\t";
		}
		cout << endl;
	}


	cout << "\n**********End*******" << endl;
}
