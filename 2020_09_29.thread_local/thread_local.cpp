#include <cstdio>
#include <thread>

extern int x;
extern int y;

int& get_x() {
	return x;
}

int& get_y() {
	return y;
}

class A {
	public:
	A() {
		get_x()++;
		printf("A constructed;\n");
	}
	~A() {
		get_y()++;
		printf("A destructed;\n");
	}
	static void g() {
		printf("G called;\n");
	}
	void f() {
		printf("F called;\n");
	}
};

thread_local A a;

int x = 0;
int y = 0;

void do_stuff() {
	a.f();
}

int main() {
	printf("Main in;\n");

	std::thread t(do_stuff);
	A::g();
	a.f();
	printf("%d %d\n", x, y);

	t.join();
	printf("Main out;\n");
	return 0;
}
