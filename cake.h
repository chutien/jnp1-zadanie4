#ifndef _CAKE_
#define _CAKE_

#include <cassert>
#include <cstddef>

#ifndef _EMPTY_
#define _EMPTY_
namespace empty {
    struct Empty {};
}
#endif // _EMPTY_

using empty::Empty;

template <class T, T length, T width, class P> class Cake {
    private:
        static constexpr double get_ln2();
        static constexpr double ln2 = get_ln2();
        int stock;
        P price;
    
    public:
        using dimension_type = T;
        using price_type = P;

        template <typename S = P> Cake(int initialStock,
            typename std::enable_if<std::is_same<S, Empty>::value>::type* = 0);
        template <typename S = P> Cake(int initialStock, P price,
            typename std::enable_if<!std::is_same<S, Empty>::value>::type* = 0);

        static constexpr double getArea();
        int getStock();

        template <typename S = P> void sell(
            typename std::enable_if<!std::is_same<S, Empty>::value>::type* = 0);
        template <typename S = P> P getPrice(
            typename std::enable_if<!std::is_same<S, Empty>::value>::type* = 0);
};


// BBP-Type Formula
template <class T, T length, T width, class P>
constexpr double Cake<T, length, width, P>::get_ln2(){
    double res = 0, denom = 1;
    for (int i = 0; i < 100; i++){
        res += 1.0 / (2 * i + 1) / denom;
        denom *= 9;
    }
    return res * 2 / 3;
}


template <class T, T length, T width, class P> template <typename S>
Cake<T, length, width, P>::Cake(const int initialStock,
    typename std::enable_if<std::is_same<S, Empty>::value>::type*)
: stock(initialStock){
    static_assert(std::is_integral<T>::value,
        "Cake got wrong parameter: lenght type should be integral.");
    assert(initialStock >= 0);
}

template <class T, T length, T width, class P> template <typename S>
Cake<T, length, width, P>::Cake(const int initialStock, P price,
    typename std::enable_if<!std::is_same<S, Empty>::value>::type*)
: stock(initialStock), price(price){
    static_assert(std::is_integral<T>::value,
        "Cake got wrong parameter: lenght type should be integral.");
    static_assert(std::is_floating_point<P>::value,
        "Cake got wrong parameter: price type should be floating point.");
    assert(initialStock >= 0);
}


template <class T, T length, T width, class P> 
constexpr double Cake<T, length, width, P>::getArea(){
    return length * width * ln2;
}

template <class T, T length, T width, class P> 
int Cake<T, length, width, P>::getStock(){
    return stock;
}


template <class T, T length, T width, class P> template <typename S>
void Cake<T, length, width, P>::sell(
        typename std::enable_if<!std::is_same<S, Empty>::value>::type*){
    assert(stock > 0);
    stock--;
}

template <class T, T length, T width, class P> template <typename S>
P Cake<T, length, width, P>::getPrice(
        typename std::enable_if<!std::is_same<S, Empty>::value>::type*){
    return price;
}


template <class T, T length, T width> using CheeseCake = Cake<T, length, width, Empty>;

template <class T, T length, T width, class P> using CreamCake = Cake<T, length, width, P>;

#endif // _CAKE_
