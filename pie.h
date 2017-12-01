#ifndef _PIE_
#define _PIE_

#include <cassert>
#include <cmath>
#include <cstddef>

#ifndef _EMPTY_
#define _EMPTY_
namespace empty {
    struct Empty {};
}
#endif // _EMPTY_

using empty::Empty;

template <class R, R radius, class P> class Pie{
    private:
        static constexpr double get_pi();
        static constexpr double pi = get_pi();
        int stock;
        P price;

    public:
        using value_type = R;
        using price_type = P;

        template <typename T = P> Pie(int initialStock, 
            typename std::enable_if<std::is_same<T, Empty>::value>::type* = 0);
        
        template <typename T = P> Pie(int initialStock, P price, 
            typename std::enable_if<!std::is_same<T, Empty>::value>::type* = 0);

        static constexpr double getArea();

        int getStock();

        template <typename T = P> void restock(int additionalStock,
            typename std::enable_if<!std::is_same<T, Empty>::value>::type* = 0);

        template <typename T = P> void sell(
            typename std::enable_if<!std::is_same<T, Empty>::value>::type* = 0);

        template <typename T = P> P getPrice(
            typename std::enable_if<!std::is_same<T, Empty>::value>::type* = 0);
};


// Formuła Viète'y
template <class R, R radius, class P> constexpr double 
    Pie<R, radius, P>::get_pi(){
    double res = 1;
    double numerator = 0;
    for (int i = 0; i < 100; i++){
        numerator = sqrt(2 + numerator);
        res = res * numerator / 2;
    }
    return 2 / res;
}


template <class R, R radius, class P> template <typename T> 
    Pie<R, radius, P>::Pie(const int initialStock, 
        typename std::enable_if<std::is_same<T, Empty>::value>::type*)
    : stock(initialStock){
    // is_integral pozwala na boole i chary, nie wiem czy powinien.
    static_assert(std::is_integral<R>::value, 
        "Pie got wrong parameter: radius type should be integral.");
    assert(initialStock >= 0);
}

template <class R, R radius, class P> template <typename T> 
    Pie<R, radius, P>::Pie(const int initialStock, P price, 
        typename std::enable_if<!std::is_same<T, Empty>::value>::type*)
    : stock(initialStock), price(price){
    // is_integral pozwala na boole i chary, nie wiem czy powinien.
    static_assert(std::is_integral<R>::value, 
        "Pie got wrong parameter: radius type should be integral.");
    static_assert(std::is_floating_point<P>::value, 
        "Pie got wrong parameter: price type should be floating point.");
    assert(initialStock >= 0);
}


template <class R, R radius, class P> constexpr double Pie<R, radius, P>::getArea(){
    return radius * radius * pi;
}

template <class R, R radius, class P> int Pie<R, radius, P>::getStock(){
    return stock;
}

template <class R, R radius, class P> template <typename T> void
Pie<R, radius, P>::restock(int additionalStock,
typename std::enable_if<!std::is_same<T, Empty>::value>::type*){
    assert(additionalStock > 0);
    stock += additionalStock;
}

template <class R, R radius, class P> template <typename T> void 
    Pie<R, radius, P>::sell(
        typename std::enable_if<!std::is_same<T, Empty>::value>::type*){
    assert(stock > 0);
    stock--;
}

template <class R, R radius, class P> template <typename T> P
    Pie<R, radius, P>::getPrice(
        typename std::enable_if<!std::is_same<T, Empty>::value>::type*){
    return price;
}


template <class R, R radius> using CherryPie = Pie<R, radius, Empty>;

template <class R, R radius, class P> using ApplePie = Pie<R, radius, P>;

#endif // _PIE_
