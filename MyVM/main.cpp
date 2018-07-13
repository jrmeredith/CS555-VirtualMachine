#include <iostream>
#include "mainFunctions.h"
#include <Windows.h>

using namespace std;

int main() {

	cout << "Jake's VM" << endl;
	cout << endl;

	pauseScreen();

	if (isFile("../sasm/sasm.exe")) {
		cout << "Found sasm.exe!" << endl;
	}
	else {
		cout << "sasm.exe not found!" << endl;
		pauseScreen();
		return 0;
	}

	system("start ../sasm/sasm.exe");
	pauseScreen();

	if (isFile("../stack-vm/stack-vm.exe")) {
		cout << "Found stack-vm.exe!" << endl;
	}
	else {
		cout << "stack-vm.exe not found!" << endl;
		pauseScreen();
		return 0;
	}

	system("start ../stack-vm/stack-vm.exe");


	pauseScreen();
	return 0;
}