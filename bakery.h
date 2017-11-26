#ifndef _BAKERY_
#define _BAKERY_

#include <cassert>

#include "pie.h"
#include "cake.h"

template <class C, class A, A shelfArea, class... P> class Bakery {
    private:
        C profits = 0;
    
    public:
        Bakery(P... products);
        C getProfits();
        template <class Product> void sell();
        template <class Product> int getProductStock();
        template <class Product> void restock(int additionalStock);
};

template <class C, class A, A shelfArea, class... P> 
    Bakery<C, A, shelfArea, P...>::Bakery(P... products){
    static_assert(std::is_floating_point<C>::value, 
                  "Bakery got wrong parameter: profits type should be floating point.");
    static_assert(std::is_integral<A>::value, 
                  "Bakery got wrong parameter: area type should be integral.");
    // TODO reszta sprawdzeń i zapisanie parametru
    
}

template <class C, class A, A shelfArea, class... P> C
    Bakery<C, A, shelfArea, P...>::getProfits(){
    return profits;    
}

//TODO reszta funkcji

#endif // _BAKERY_
