#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::hex;

int main() {
	ifstream fs { "test_file" };
	uint8_t x;
	while(fs >> x) {
		cout << hex << int { x } << " ";
	}
	cout << "Unsigneds:\n";
	cout << typeid(uint8_t ).name() << "\n";
	cout << typeid(uint16_t).name() << "\n";
	cout << typeid(uint32_t).name() << "\n";
	cout << typeid(uint64_t).name() << "\n";
	cout << "Signeds:\n";
	cout << typeid(int8_t ).name() << "\n";
	cout << typeid(int16_t).name() << "\n";
	cout << typeid(int32_t).name() << "\n";
	cout << typeid(int64_t).name() << "\n";

	cout << " x type: " << typeid( x).name() << "\n";
	cout << "+x type: " << typeid(+x).name() << "\n";
}
