#include "stack-vm.h"
using namespace std;

int main() {
	StackVM vm;
	vector<i32> prog{3, 4, 0x40000001, 0x40000000 };
	vm.loadProgram(prog);
	cout << "Program loaded" << endl;
	vm.run();

	return 0;
}