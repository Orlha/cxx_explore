#include <cstdio>
#include <string>

void ref(std::string& v) {
	std::printf("Received an lvalue ref;\n");
	v = "222";
}

void ref(const std::string& v) {
	std::printf("Received a const lvalue ref;\n");
}

void ref(std::string&& v) {
	std::printf("Received an rvalue ref;\n");
}

void ref(const std::string&& v) {
	std::printf("Received a const rvalue ref;\n");
}

std::string create() {
	return "";
}

const std::string const_create() {
	return "";
}


template<typename T>
void check(T&& t) {
	//std::printf("Template function called;\n");
	ref(std::forward<T>(t));
	//ref(std::move(t));
	//printf("%s\n", t.c_str());
}

int main() {
	std::string s1 = "1";
	const std::string s2 = "1";
	check(s1);
	check(std::string {});
	check(create());
	check(s2);
	check(const_create());
	return 0;
}
