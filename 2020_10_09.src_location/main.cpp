#include <experimental/source_location>
//#include <source_location>
#include <iostream>

class ClassName {
	public:
	ClassName() {
	std::experimental::source_location q = std::experimental::source_location::current();
	std::cout << q.file_name() << " " << q.function_name() << ":" << q.line() << "\n";

	}
	void MethodName() {
	std::experimental::source_location q = std::experimental::source_location::current();
	std::cout << q.file_name() << " " << q.function_name() << ":" << q.line() << "\n";

	}

};

void a() {
	std::experimental::source_location q = std::experimental::source_location::current();
	std::cout << q.file_name() << " " << q.function_name() << ":" << q.line() << "\n";
}

int main() {
	std::experimental::source_location q = std::experimental::source_location::current();
	std::cout << q.file_name() << " " << q.function_name() << ":" << q.line() << "\n";
	a();

	ClassName fgh;
	fgh.MethodName();

}
