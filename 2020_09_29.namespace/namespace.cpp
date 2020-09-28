#include <string>
#include <iostream>
#include <c.h>

using u8 = unsigned char;

class A {
	inline static u8 memory[1024];
	static u8* ptr;
	private:
	public:
	A() {
		using namespace std;
		cout << "Constructed A;\n";
	}
	void* operator new(size_t size) {
		using namespace std;
		cout << "Using overloaded new of A;\n";
		auto tmp = ptr;
		ptr += size;
		return tmp;
	}
};

u8* A::ptr = A::memory;

class B {
	B() {
		using namespace std;
		cout << "Constructed B;\n";
	}

};

int main() {
	A a1;
	auto a2 { A() };
	auto a3 { A{} };
	auto a4 = new A;
	auto a5 = new A();
	auto a6 = new A{};
	return 0;
}
