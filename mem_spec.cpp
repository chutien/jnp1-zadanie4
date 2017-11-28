#include <iostream>
//#include <type_traits>

template <typename Type>
struct Foo {
    template <typename T = Type>
    void function1(float a, float b, typename std::enable_if<!std::is_same<T, float>::value>::type *c = 0) {
        std::cout << "float\n";
    }
    void function1(float a, Type b) {
       std::cout << "type\n";
    }
};

int main() {
    Foo<float> f;
    f.function1(1, 1);
    f.function1(1.0f,1.0f);
    Foo<int> g;
    g.function1(1,1);
    g.function1(1.0f,1.0f);
    g.function1(1.0,1.0); // warning!
}