#ifndef _PIE_
#define _PIE_

#include <cassert>
#include <cmath>

// Formuła Viète'y
constexpr double get_pi(){
    long double res = 1;
    long double numerator = 0;
    for (int i = 0; i < 100; i++){
        numerator = sqrt(2 + numerator);
        res = res * numerator / 2;
    }
    return 2 / res;
}

template <class R, R radius, class P, bool sellable> class Pie {
    protected:
        static constexpr long double pi = get_pi();
        int stock;
        bool is_sellable;
        //TODO: Empty struct
        P price;
    
    public:
        //TODO: poblokować
        Pie(int initialStock);
        Pie(int initialStock, P price);
        int getStock();
        static double getArea();
        void sell();
        P getPrice();
};

template <class R, R radius, class P, bool sellable> Pie<R, radius, P, sellable>::Pie(const int initialStock) 
    : stock(initialStock){ 
    // is_integral pozwala na boole i chary, nie wiem czy powinien.
    static_assert(std::is_integral<R>::value, 
                  "Pie got wrong parameter: radius type should be integral.");
    /*Pie<R, radius, P>::Pie(int initialStock, P price) {
    static_assert(std::is_floating_point<P>::value, 
                  "Pie got wrong parameter: price type should be floating point.");*/
    assert(initialStock >= 0);
}

template <class R, R radius, class P, bool sellable> Pie<R, radius, P, sellable>::Pie(const int initialStock, P price) 
    : stock(initialStock){ 
    // is_integral pozwala na boole i chary, nie wiem czy powinien.
    static_assert(std::is_integral<R>::value, 
                  "Pie got wrong parameter: radius type should be integral.");
    /*Pie<R, radius, P>::Pie(int initialStock, P price) {
    static_assert(std::is_floating_point<P>::value, 
                  "Pie got wrong parameter: price type should be floating point.");*/
    assert(initialStock >= 0);
    this->price = price;
}

template <class R, R radius, class P, bool sellable> double Pie<R, radius, P, sellable>::getArea(){
    return radius * radius * pi;
}

template <class R, R radius, class P, bool sellable> int Pie<R, radius, P, sellable>::getStock(){
    return stock;
}

template <class R, R radius, class P, bool sellable> void Pie<R, radius, P, sellable>::sell(){
    assert((Pie<R, radius, P, sellable>::stock > 0));
    Pie<R, radius, P, sellable>::stock--;
}

template <class R, R radius, class P, bool sellable> P Pie<R, radius, P, sellable>::getPrice(){
    return price;
}

template <class R, R radius> using CherryPie = Pie<R, radius, double, false> ;

template <class R, R radius, class P> using ApplePie = Pie<R, radius, P, true>;

#endif // _PIE_
