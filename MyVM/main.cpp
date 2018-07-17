#include <iostream>
#include <Windows.h>
#include "mainFunctions.h"
#include <string>

using namespace std;

int main() {
	LPCSTR sasm = "../sasm/sasm.exe";
	LPCSTR stackvm = "../stack-vm/stack-vm.exe";

	welcome();
	cout << endl;

	instructions();
	userCommands("../sasm/test.sasm");
	cout << endl;

	startProcess(sasm);

	cout << endl;

	
	startProcess(stackvm);

	pauseScreen();
	return 0;
}