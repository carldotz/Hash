#include <iostream>
#include "HashTab.h"

using std::cout;
using std::endl;

int main() {
	HashTab ht(10);

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
	cout << "\n**********End*******" << endl;
}
