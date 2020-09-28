#include <cstdio>

using namespace std;

class A {
	private:
	int a = 0;
	void print() {
		printf("A Value: %d\n", a);
	}
	public:
	virtual static void example() {
		A a;
		a.print();
	}
};

class B: public A {
	private:
	int b = 1;
	void print() {
		printf("B Value: %d\n", b);
	}
	public:
	virtual static void example() {
		B b;
		b.print();
	}
};

int main() {

	A* a = new B();
	a->example();
	return 0;
}
