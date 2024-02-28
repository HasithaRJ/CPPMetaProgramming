#include <iostream>

// Recursive template metaprogramming to calculate Fibonacci numbers
template <int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// Base cases
template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

int main() {
    constexpr int n = 10; // Change this to calculate Fibonacci(n)

    std::cout << "Fibonacci(" << n << ") = " << Fibonacci<n>::value << std::endl;

    return 0;
}

/*
compiler will create 9 instantiatians From Fibonacci<10> to Fibonacci<2>
*/
