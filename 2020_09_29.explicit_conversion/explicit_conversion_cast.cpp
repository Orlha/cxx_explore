#include <cstdio>
#include <type_traits>

template<typename T>
concept Integral = std::is_integral<T>::value;

template<typename T>
concept Arithmetic = std::is_arithmetic<T>::value;

template<typename T>
constexpr bool is_printable() {
	return false;
}

#if 0
template<typename T>
concept Printable = requires(T t) {
	t.print();
};
#endif

template<typename T>
concept Printable = requires(T t) {
	t.print();
	t.qwe();
};


template<typename T> requires Printable<T>
void do_stuff() {
	printf("Doing stuff;\n");
	T t(4);
	t.print();
}

class Value {
	int x;
	public:
	Value(int x): x(x) {}
	explicit operator int() {
		return x;
	}
	void print() {}
};

int main() {
	do_stuff<Value>();

	Value v { 5 };
	int g { v };
	g = static_cast<int>(v);
}
