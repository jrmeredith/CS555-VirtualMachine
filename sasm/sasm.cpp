#include <iostream>
#include <fstream>
#include <string>
#include "lexer.h"

typedef uint32_t i32;

using namespace std;

// Functions
vector<i32> compileToInstructions(strings s);
bool isInteger(string s);
bool isPrimitive(string s);
i32 mapToNumber(string s);

void pauseScreen();

int main() {
	cout << "SASM running!" << endl;
	string fileDir = "../sasm/test.sasm";

	// read input file
	ifstream inFile;
	inFile.open(fileDir);

	if (!inFile.is_open()) {
		cout << "Error: could not open [" << fileDir << "]" << endl;
		exit(1);
	}

	cout << "Found " << fileDir << "!" << endl;

	string line;
	string contents;
	while (getline(inFile, line)) {
		contents += line + "\n";
	}
	inFile.close();

	// parse file
	Lexer lexer;
	strings lexemes = lexer.lex(contents);
	
	// compile to binary
	vector<i32> instructions = compileToInstructions(lexemes);

	// write to binary file
	ofstream oFile;
	oFile.open("../sasm/out.bin", ios::binary);
	cout << "Writting to out.bin..." << endl;
	for (i32 i = 0; i < instructions.size(); i++) {
		oFile.write(reinterpret_cast<char *>(&instructions[i]), sizeof(i32));
	}
	oFile.close();
	cout << "Done!" << endl;
	//pauseScreen();
	return 0;
}

vector<i32> compileToInstructions(strings s) {
	vector<i32> instructions;
	for (i32 i = 0; i < s.size(); i++) {
		if (isInteger(s[i])) {
			instructions.push_back(stoi(s[i]));
		}
		else {
			i32 instruction = mapToNumber(s[i]);
			if (instruction != -1) {
				instructions.push_back(instruction);
			}
			else {
				cout << "Error: Invalid instruction [" << s[i] << "]" << endl;
			}
		}
	}
	instructions.push_back(0x40000000);	// always halt at the end
	return instructions;
}

bool isInteger(string s) {
	for (i32 i = 0; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
		else {
			return true;
		}
	}
}

i32 mapToNumber(string s) {
	if (s == "+") {
		return 0x40000001;
	}
	else if (s == "-") {
		return 0x40000002;
	}
	else if (s == "*") {
		return 0x40000003;
	}
	else if (s == "/") {
		return 0x40000004;
	}
	else {
		return -1;	// invalid instruction
	}
}

void pauseScreen() {
	cout << endl;
	cout << "Press return to continue..." << flush;
	cin.get();
}