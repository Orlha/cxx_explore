#include <iostream>
//#include <array>
//#include <numeric>
//#include <iomanip>
//#include <cfloat>


enum A {
	A1, A2, A3
};

enum B {
	B1, B2, B3
};

enum class C {
	C1, C2, C3
};

namespace Scoped {
	enum class D {
		D1, D2, D3
	};
	static std::string to_string(D d) {
		switch(d) {
			case D::D1: return "D1";
			case D::D2: return "D2";
			case D::D3: return "D3";
		}
	}
}

#if 1
static std::string to_string(A a) {
	switch(a) {
		case A1: return "A1";
		case A2: return "A2";
		case A3: return "A3";
	}
}
#endif

static void print_what();

class EClass {
	public:
	enum E {
		E1, E2, E3,
	};
friend std::string to_string(EClass::E e) {
	switch(e) {
		case EClass::E1: return "E1";
		case EClass::E2: return "E2";
		case EClass::E3: return "E3";
	}
}
friend void print_ok(EClass a) {
	std::cout << "ok\n";
}
friend void print_what() {
	std::cout << "what\n";
}
};



namespace Logger {

template<typename T>
concept Stringable = requires (T x) { to_string(x); };

template<typename T>
concept Enum = std::is_enum<T>::value;

template<Enum T>
void log(T t) {
	if constexpr(Stringable<T>) {
		std::cout << to_string(t) << "\n";
	} else {
		std::cout << static_cast<typename std::underlying_type<T>::type>(t) << "\n";
	}
}

}

using Logger::log;

int main() {
	log(A2);
	log(B2);
	log(C::C2);
	log(Scoped::D::D2);
	log(EClass::E::E2);
	EClass ec1;
	//std::cout << ::to_string(EClass::E2);
	print_ok(EClass{});
	print_what();
	//ec1.to_string(EClass::E2);
	//std::cout << EClass::to_string(E2);

}
