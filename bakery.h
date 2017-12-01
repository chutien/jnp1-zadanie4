#ifndef _BAKERY_
#define _BAKERY_

#include <cassert>
#include <type_traits>

#ifndef _EMPTY_
#define _EMPTY_
namespace emp {
    struct Empty {};
}
#endif // _EMPTY_

namespace bake {
    template <class... P> struct is_unique : std::true_type{};
    template <class P> struct is_unique<P, P> : std::false_type{};
    template <class P1, class P2> struct is_unique<P1, P2> : std::true_type{};
    template <class P1, class P2, class... P> struct is_unique<P1, P2, P...> :
        std::conjunction<
            is_unique<P1, P2>, is_unique<P1, P...>, is_unique<P2, P...>
        >{};

    template <class C, class... P> struct prices_match : std::true_type{};
    template <class C, class P1, class... P> struct prices_match<C, P1, P...> :
        std::conjunction<
            std::disjunction<
                std::is_same<C, typename P1::price_type>,
                std::is_same<emp::Empty, typename P1::price_type>
            >,
            prices_match<C, P...>
        >{};

    template <class A, class... P> struct dim_match : std::true_type{};
    template <class A, class P1, class... P>
    struct dim_match<A, P1, P...> :
        std::conjunction<
            std::is_same<A, typename P1::dimension_type>, dim_match<A, P...>
        >{};
}

template <class C, class A, A shelfArea, class... P> class Bakery {
    private:
        C profits = 0;
        std::tuple<P...> breadstuff;
        template <class... Args> static constexpr auto sumAreas();

    public:
        Bakery() = delete;
        Bakery(P... products);
        C getProfits();
        template <class Product> void sell();
        template <class Product> int getProductStock();
        template <class Product> void restock(int additionalStock);
};

template <class C, class A, A shelfArea, class... P>
Bakery<C, A, shelfArea, P...>::Bakery(P... products) : breadstuff(products...){
    static_assert(std::is_floating_point<C>::value, "Bakery got wrong parameter"
            ": profits type should be floating point.");
    static_assert(std::is_integral<A>::value, "Bakery got wrong parameter: "
            "area type should be integral.");
    static_assert(bake::is_unique<P...>::value, "Bakery got wrong parameter: "
            "product types should be unique.");
    static_assert(shelfArea >= sumAreas<P...>(), "Bakery got wrong parameter: "
            "total sum of product areas is greater than bakery's shelf area.");
    static_assert(bake::dim_match<A, P...>::value, "Bakery got wrong parameter:"
            " dimension types of products do not match.");
    static_assert(bake::prices_match<C, P...>::value, "Bakery got wrong "
            "parameter: price types of products do not match.");
}

template <class C, class A, A shelfArea, class... P> template <class... Args>
constexpr auto Bakery<C, A, shelfArea, P...>::sumAreas() {
    return (... + Args::getArea());
}

template <class C, class A, A shelfArea, class... P>
C Bakery<C, A, shelfArea, P...>::getProfits(){
    return profits;
}

template <class C, class A, A shelfArea, class... P> template <class Product>
void Bakery<C, A, shelfArea, P...>::sell(){
    if (std::get<Product>(breadstuff).getStock() > 0){
        profits += std::get<Product>(breadstuff).getPrice();
        std::get<Product>(breadstuff).sell();
    }
}

template <class C, class A, A shelfArea, class... P> template <class Product>
int Bakery<C, A, shelfArea, P...>::getProductStock(){
    return std::get<Product>(breadstuff).getStock();
}

template <class C, class A, A shelfArea, class... P> template <class Product>
void Bakery<C, A, shelfArea, P...>::restock(int additionalStock){
    assert(additionalStock >= 0);
    std::get<Product>(breadstuff).restock(additionalStock);
}

#endif // _BAKERY_
