#include <cstdio>

class BaseA {
	public:
		int a = 1;
};

class BaseB {
	public:
		int b = 2;
};

class C: public BaseA, public BaseB {
	public:
		int c = 3;
};

class x1 {
	public:
		virtual void x() {
			std::printf("base;\n");
		}
};

class y1 {
	public:
		virtual void x() {
			std::printf("base;\n");
		}
};

class x2: public x1 {
	public:
		virtual void x() {
			std::printf("derived;\n");
		}
};

int main() {
	C* c = new C();
	BaseB* b = static_cast<BaseB*>(c);
	BaseA* a = static_cast<BaseA*>(c);
	std::printf("C* %p\n", c);
	std::printf("B* %p\n", b);
	std::printf("A* %p\n", a);
	std::printf("x  %p\n", &c->c);

	BaseB* bb = (BaseB*)c;
	std::printf("b* %p\n", bb);
	std::printf("value %d\n", bb->b);

	bb = reinterpret_cast<BaseB*>(c);
	std::printf("b* %p\n", bb);
	std::printf("value %d\n", bb->b);

	auto* y_1 = new y1();


	auto* x_2 = new x2();
	x1* x_1 = x_2;
	auto* x_3 = dynamic_cast<x2*>(y_1);
	if(x_3) {
		x_3->x();
	} else {
		std::printf("bad cast;\n");
	}
	
	return 0;
}
