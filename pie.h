#ifndef _PIE_
#define _PIE_

#include <cassert>
#include <cmath>
#include <cstddef>

//template <class R, R radius, class P> class Pie{};

struct Empty {};

template <class R, R radius, class P> class Pie{
    private:
        static constexpr double get_pi();
        static constexpr long double pi = get_pi();
        int stock;
        bool is_sellable;
        //TODO: Empty struct
        P price;
    
    public:
        //TODO: poblokować
        Pie(int initialStock);
        //Pie(int initialStock, P price);
        int getStock();
        static double getArea();
        //void sell();
        //P getPrice();
};

//template <bool ok> class Pie{};
//template <> class Pie <true> {};
template <class R, R radius> class Pie <R, radius, Empty>{
    private:
        static constexpr double get_pi();
        static constexpr long double pi = get_pi();
        int stock;
        bool is_sellable;
        //TODO: Empty struct
        Empty price;
    
    public:
        //TODO: poblokować
        Pie(int initialStock);
        //Pie(int initialStock, P price);
        int getStock();
        static double getArea();
        //void sell();
        //P getPrice();
};

// Formuła Viète'y
template <class R, R radius, class P> constexpr double Pie<R, radius, P>::get_pi(){
    long double res = 1;
    long double numerator = 0;
    for (int i = 0; i < 100; i++){
        numerator = sqrt(2 + numerator);
        res = res * numerator / 2;
    }
    return 2 / res;
}


// Formuła Viète'y
template <class R, R radius> constexpr double Pie<R, radius, Empty>::get_pi(){
    long double res = 1;
    long double numerator = 0;
    for (int i = 0; i < 100; i++){
        numerator = sqrt(2 + numerator);
        res = res * numerator / 2;
    }
    return 2 / res;
}


template <class R, R radius, class P> Pie<R, radius, P>::Pie(const int initialStock) 
    : stock(initialStock){ 
    // is_integral pozwala na boole i chary, nie wiem czy powinien.
    static_assert(std::is_integral<R>::value, 
                  "Pie got wrong parameter: radius type should be integral.");
    /*Pie<R, radius, P>::Pie(int initialStock, P price) {
    static_assert(std::is_floating_point<P>::value, 
                  "Pie got wrong parameter: price type should be floating point.");*/
    assert(initialStock >= 0);
}
//typename std::enable_if<sellable, P>::type
// template <class R, R radius, class P, bool sellable> 
//     Pie<R, radius, P, sellable>::Pie(const int initialStock, P price) 
//     : stock(initialStock){ 
//     // is_integral pozwala na boole i chary, nie wiem czy powinien.
//     static_assert(std::is_integral<R>::value, 
//                   "Pie got wrong parameter: radius type should be integral.");
//     /*Pie<R, radius, P>::Pie(int initialStock, P price) {
//     static_assert(std::is_floating_point<P>::value, 
//                   "Pie got wrong parameter: price type should be floating point.");*/
//     assert(initialStock >= 0);
//     this->price = price;
// }

template <class R, R radius, class P> double Pie<R, radius, P>::getArea(){
    return radius * radius * pi;
}

template <class R, R radius> double Pie<R, radius, Empty>::getArea(){
    return radius * radius * pi;
}

template <class R, R radius> int Pie<R, radius, Empty>::getStock(){
    return stock;
}

template <class R, R radius, class P> int Pie<R, radius, P>::getStock(){
    return stock;
}

/*template <class R, R radius, class P, bool sellable> void Pie<R, radius, P, sellable>::sell(){
    assert((Pie<R, radius, P, sellable>::stock > 0));
    Pie<R, radius, P, sellable>::stock--;
}

template <class R, R radius, class P, bool sellable>
P 
Pie<R, radius, P, sellable>::getPrice(){
    return price;
}*/

template <class R, R radius> using CherryPie = Pie<R, radius, Empty>;

template <class R, R radius, class P> using ApplePie = Pie<R, radius, P>;

#endif // _PIE_
