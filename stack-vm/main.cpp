#include <iostream>
#include <fstream>
#include "stack-vm.h"
using namespace std;

void pauseScreen();

int main() {
	cout << "Stack-VM Running!" << endl;
	string fileDir = "../sasm/out.bin";
	ifstream inFile;
	
	inFile.open(fileDir, ios::binary);

	if (!inFile.is_open()) {
		cout << "Could not open file!" << endl;
		pauseScreen();
		return 0;
	}
	else {
		cout << "out.bin found!" << endl;
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
	//pauseScreen();
	return 0;
}

void pauseScreen() {
	cout << endl;
	cout << "Press return to continue..." << flush;
	cin.get();
}