#include "stack-vm.h"
using namespace std;

/*
 * Instruction format:
 * header: 2 bits
 * data: 30 bits
 *
 * header format:
 * 0 => positive integer
 * 1 => primitive instruction
 * 2 => negative integer
 * 3 => undefined
 */

// Functions
StackVM::StackVM() {
	//memory.reserve(1000000);
	memory.resize(1000000);
}

i32 StackVM::getType(i32 instruction) {
	i32 type = 0xC0000000;
	type = (type & instruction) >> 30;
	return type;
}

i32 StackVM::getData(i32 instruction) {
	i32 data = 0x3FFFFFFF;
	data = data & instruction;
	return data;
}

void StackVM::fetch() {
	pc++;
}

void StackVM::decode() {
	typ = getType(memory[pc]);
	dat = getData(memory[pc]);
}

void StackVM::execute() {
	if (typ == 0 || typ == 2) {
		sp++;
		memory[sp] = dat;
	}
	else {
		doPrimitive();
	}
}

void StackVM::doPrimitive() {
	switch (dat) {
	case 0:	// halt
		cout << "halt" << endl;
		running = 0;
		break;
	case 1:	// add
		cout << "add " << memory[sp - 1] << " " << memory[sp] << endl;
		memory[sp - 1] = memory[sp - 1] + memory[sp];
		sp--;
		break;
	}
}

void StackVM::run() {
	pc -= 1;
	while (running == 1) {
		fetch();
		decode();
		execute();
		cout << "tos: " << memory[sp] << endl;
	}
}
 
void StackVM::loadProgram(vector<i32> prog) {
	//i32 vecSize = prog.size();
	for (i32 i = 0; i < prog.size(); i++) {
		memory[pc + i] = prog[i];
	}
	cout << "Program loaded successfully!" << endl;
	cout << endl;
}