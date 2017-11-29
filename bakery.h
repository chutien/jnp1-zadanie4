#ifndef _BAKERY_
#define _BAKERY_

#include <cassert>
#include <type_traits>
#include <iostream>
#include <typeinfo>

//#include "pie.h"
//#include "cake.h"

using std::tuple;

//TODO ukryc
/*template <class... P> struct is_unique;
template <class P> struct is_unique<P> : std::true_type{};
template <class P> struct is_unique<P, P> : std::false_type{};
template <class P1, class P2> struct is_unique<P1, P2> : std::true_type{};
template <class P1, class P2, class... P> struct is_unique<P1, P2, P...> :
  std::conjunction<is_unique<P1, P2>, is_unique<P1, P...>, is_unique<P2, P...>>{};

template <class P1, class... P> struct is_contained;
template <class P> struct is_contained<P> : std::false_type{};
template <class P1, class P2> struct is_contained<P1, P2> : std::is_same<P1, P2>{};
template <class P1, class P2, class... P> struct is_contained<P1, P2, P...> :
  std::disjunction<is_contained<P1, P2>, is_contained<P1, P...>>{};*/


/* TODO
template <class A, A shelfArea, class... P> struct meetsPriceTypeRequirement;
template <class A, A shelfArea, class P> struct meetsPriceTypeRequirement<A, shelfArea, P> :
  std::is_same<std::invoke_result<decltype(&P::getArea)(P)>, A>{};
template <class A, A shelfArea, class P1, class... P> struct meetsPriceTypeRequirement<A, shelfArea, P1, P...> :
  std::conditional<
  std::is_member_function_pointer<decltype(&P1::getPrice)>::value, 
    std::conjunction<
        std::is_same<std::invoke_result<decltype(&P1::getPrice)(P1)>, A>,
        meetsPriceTypeRequirement<A, shelfArea, P...>
  >,
  std::true_type
  >{};
*/

/* TODO: dodac pole applepie i sprawdzac to pole
template <class P> struct is_apple_pie : std::false_type{};
*/

/* TODO: dodac pole sprzedawalne i sprawdzac to pole
template<class P, class = void> struct can_be_sold : std::false_type {};
template<class P> struct can_be_sold<P, class std::enable_if<
  !std::is_same<decltype(std::declval<P>().getPrice), void>::value>::type
> : std::true_type{};

template <class A, class... P> struct is_price_ok;
template <class A, class P> struct is_price_ok<A, P> : can_be_sold<P>{};
template <class A, class P1, class... P> struct is_price_ok<A, P1, P...> :
    std::conjunction<is_price_ok<A, P1>, is_price_ok<A, P...>>{};
*/

template <class C, class A, A shelfArea, class... P> class Bakery {
    private:
        C profits = 0;
        //std::type_info* t;
        tuple<P...> breadstuff;
    
    public:
        Bakery(P... products);
        C getProfits();
        template <class Product> void sell();
        template <class Product> int getProductStock();
        template <class Product> void restock(int additionalStock);
};

/*template<class *S, class... P> struct unfold_products {
    S value;
    unfold_products(S s, P... p){
        value = s;
    }
};*/

template <class C, class A, A shelfArea, class... P> 
    Bakery<C, A, shelfArea, P...>::Bakery(P... products)
    : breadstuff(products...){
    static_assert(std::is_floating_point<C>::value, 
                  "Bakery got wrong parameter: profits type should be floating point.");
    static_assert(std::is_integral<A>::value,
                  "Bakery got wrong parameter: area type should be integral.");
    //static_assert(is_unique<P...>::value,
    //              "Bakery got wrong parameter: product types should be unique.");
    /*
    static_assert(is_price_ok<A, P...>::value,
                  "Bakery got wrong parameter: product price types should be the same as C.");
    */
    // TODO reszta sprawdzeń i zapisanie parametru
    std::cout << "tworze piekarnie\n";
    //std::type_info& t = typeid(unfold_products<P...>(products...).value);
    std::cout << std::get<0>(breadstuff).getArea() << std::endl; //<- how to get 0 element of the tuple
    
}

template <class C, class A, A shelfArea, class... P> C
    Bakery<C, A, shelfArea, P...>::getProfits(){
    return profits;    
}

//TODO reszta funkcji
template <class C, class A, A shelfArea, class... P> template <class Product>
void Bakery<C, A, shelfArea, P...>::sell(){
    
}

template <class C, class A, A shelfArea, class... P> template <class Product>
  int Bakery<C, A, shelfArea, P...>::getProductStock(){
    //static_assert(is_contained<Product, P...>::value,
    //            "getProductStock got wrong parameter: Product is not valid baking type.");

}

template <class C, class A, A shelfArea, class... P> template <class Product>
  void Bakery<C, A, shelfArea, P...>::restock(int additionalStock){
}

#endif // _BAKERY_
