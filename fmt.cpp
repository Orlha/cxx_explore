#include <string>
#include <fmt/core.h>

using std::string;
using fmt::print;
using fmt::format;

int main() {
	print("So, how do {} like {}?\n", "you", "this");

	string s = format("The result of this calculation is {1}, {0}", "cool?", 15);
	print(s);
	print("\n");
	print("{}\n", s);

}
