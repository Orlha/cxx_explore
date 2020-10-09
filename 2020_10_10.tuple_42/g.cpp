#include <iostream>
#include <tuple>

template<typename ...Args>
auto UniversalAnswer(Args&&...iArgs)
{
    return [iArgs = std::make_tuple(std::forward<Args>(iArgs) ...)] (auto&&... iQuestions) {
        return 42;
    };
}

int main()
{
    auto theAnswer = UniversalAnswer("ka", "me", "ha")("me", "ha");
    std::cout << theAnswer << '\n';
    return theAnswer;
}
