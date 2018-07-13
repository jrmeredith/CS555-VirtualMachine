#include <iostream>
#include <Windows.h>
#include "mainFunctions.h"
using namespace std;

void userCommands(const string dir) {
	ofstream outFile;
	outFile.open(dir);
	string input;
	string toFile = "";

	getline(cin, input);
	
	outFile << input;
	outFile.close();
}

void instructions() {
	cout << "Please enter the integers along with the instructions you wish to push onto the stack." << endl;
	cout << "You must push two integers to begin with, followed by an operation (+, -, *, /)." << endl;
	cout << "Every character must be separated by a space." << endl;
	cout << "(Example: 2 4 + 1 -) This will add 2 and 4 then subtract 1." << endl << endl;
	cout << "$ " << flush;
}

void pauseScreen() {
	cout << endl;
	cout << "Press return to continue... " << flush;
	cin.get();
}

bool isFile(const char *name) {
	ifstream myFile(name);
	return myFile.good();
}

void startProcess(const char *dir) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	CreateProcess(dir, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}