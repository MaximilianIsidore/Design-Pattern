#include <iostream>
#include <vector>
#include <type_traits>

template <typename T> struct S {
    typename T::value_type f() { return 0; }
};

int main() {
    S<std::vector<int>> sv;
    std::cout<<sv.f()<<std::endl;
    //S<int> si; // Does not compile
}