#include <iostream>
#include <fstream>
#include "stack-vm.h"
using namespace std;

void pauseScreen();

int main() {

	ifstream inFile;
	
	inFile.open("../sasm/out.bin", ios::in | ios::binary);

	if (!inFile.is_open()) {
		cout << "Could not open file!" << endl;
		cout << endl;
		pauseScreen();
		return 0;
	}
	else {
		cout << "out.bin found!" << endl;
		cout << endl;
	}

	i32 i;
	vector<i32> prog;
	
	while (inFile.read((char*)&i, sizeof(i))) {
		prog.push_back(i);
	}

	inFile.close();

	StackVM vm;
	vm.loadProgram(prog);
	vm.run();
	pauseScreen();
	return 0;
}

void pauseScreen() {
	cout << endl;
	cout << "Press return to continue..." << flush;
	cin.get();
}