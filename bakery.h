#ifndef _BAKERY_
#define _BAKERY_

#include <cassert>
#include <type_traits>
#include <iostream>
#include <typeinfo>

//#include "pie.h"
//#include "cake.h"

using std::tuple;
using std::get;


//TODO ukryc
template <class... P> struct is_unique : std::true_type{};
template <class P> struct is_unique<P, P> : std::false_type{};
template <class P1, class P2> struct is_unique<P1, P2> : std::true_type{};
template <class P1, class P2, class... P> struct is_unique<P1, P2, P...> :
    std::conjunction<
            is_unique<P1, P2>, is_unique<P1, P...>, is_unique<P2, P...>
    >{};

/*
template <typename T> struct first_param;
template <template <typename, typename...> class C, typename T, typename ...Ts>
struct first_param<C<T, Ts...>>
{
    using type = T;
};
*/

template <class C, class A, A shelfArea, class... P> class Bakery {
    private:
        C profits = 0;
        tuple<P...> breadstuff;

        template <class... K> struct prices_match : std::true_type{};
        template <class K, class... R> struct prices_match<K, R...> :
            std::conjunction<
                std::disjunction<
                    std::is_same<C, decltype(K::price)>,
                    std::bool_constant<!K::is_sellable>
                >,
                prices_match<R...>
            >
        {};

        template <class... Args> static constexpr auto sum_areas() {
            return (... + Args::getArea());
        }

        template <class... K> struct dim_match : std::true_type{};
        template <class K1, class... K> struct dim_match<K1, K...> :
            std::conjunction<std::is_same<A, typename K1::value_type>, dim_match<K...>>{};



public:
        Bakery(P... products);
        C getProfits();
        template <class Product> void sell();
        template <class Product> int getProductStock();
        template <class Product> void restock(int additionalStock);
};

template <class C, class A, A shelfArea, class... P>
Bakery<C, A, shelfArea, P...>::Bakery(P... products) : breadstuff(products...){
    static_assert(std::is_floating_point<C>::value, 
                  "Bakery got wrong parameter: profits type should be floating point.");
    static_assert(std::is_integral<A>::value,
                  "Bakery got wrong parameter: area type should be integral.");
    static_assert(is_unique<P...>::value,
                  "Bakery got wrong parameter: product types should be unique.");
    static_assert(shelfArea >= sum_areas<P...>(),
                  "Bakery got wrong parameter: total sum of product areas is greater than bakery's shelf area.");
    static_assert(dim_match<P...>::value,
                  "Bakery got wrong parameter: dimension types do not match.");
    static_assert(prices_match<P...>::value,
                  "Bakery got wrong parameter: price types do not match.");
}

template <class C, class A, A shelfArea, class... P>
C Bakery<C, A, shelfArea, P...>::getProfits(){
    return profits;
}

template <class C, class A, A shelfArea, class... P> template <class Product>
void Bakery<C, A, shelfArea, P...>::sell(){
    if (get<Product>(breadstuff).getStock() > 0){
        profits += get<Product>(breadstuff).getPrice();
        get<Product>(breadstuff).sell();
    }
}

template <class C, class A, A shelfArea, class... P> template <class Product>
int Bakery<C, A, shelfArea, P...>::getProductStock(){
    //static_assert(std::is_same<typename first_param<Product>::type, A>::value, "ELO");
    return get<Product>(breadstuff).getStock();
}

template <class C, class A, A shelfArea, class... P> template <class Product>
void Bakery<C, A, shelfArea, P...>::restock(int additionalStock){
    static_assert(std::is_same<C, decltype(Product::price)>::value &&
            Product::get_pi(), "Product should be apple pie.");
    get<Product>(breadstuff).stock += additionalStock;
}

#endif // _BAKERY_
