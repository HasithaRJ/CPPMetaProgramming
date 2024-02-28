#include <iostream>

// Primary template for Typelist
template <typename... Types>
struct Typelist {};

// Base case: Empty typelist
template <typename T>
struct PrintTypes {
    static void print() {
        std::cout << "End of typelist" << std::endl;
    }
};

// Recursive case: Print the first type and recurse on the rest
template <typename First, typename... Rest>
struct PrintTypes<Typelist<First, Rest...>> {
    static void print() {
        std::cout << typeid(First).name() << std::endl;
        PrintTypes<Typelist<Rest...>>::print();
    }
};

int main() {
    using MyTypelist = Typelist<int, double, char>;
    PrintTypes<MyTypelist>::print();           
    return 0;
}

/* ----------------------------- Notes -----------------------------
Compile will generate 4 instantiations. Use https://cppinsights.io/ to see the implemetations
1. struct PrintTypes<Typelist<double, char> > - instantiated from line 20
2. struct PrintTypes<Typelist<char> >         - instantiated from line 20
3. struct PrintTypes<Typelist<> >             - instantiated from line 20 (base case generated according to base function in line no 9)
4. PrintTypes<Typelist<int, double, char> >   - instantiated from line 26
*/
