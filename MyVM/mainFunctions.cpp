#include <iostream>
#include "mainFunctions.h"
using namespace std;

void pauseScreen() {
	cout << endl;
	cout << "Press return to continue... " << flush;
	cin.get();
}

bool isFile(const char *name) {
	ifstream myFile(name);
	return myFile.good();
}