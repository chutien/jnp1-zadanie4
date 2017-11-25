#ifndef _PIE_
#define _PIE_

template <class R, R radius> class Pie {
    protected:
        static constexpr double pi = 3.141; //TODO wyliczac w czasie kompilacji
        int stock;
    
    public:
        explicit Pie(int initialStock);
        static double getArea();
        int getStock();
};

template <class R, R radius> double Pie<R, radius>::getArea(){
    return radius * radius * pi;
}


template <class R, R radius> int Pie<R, radius>::getStock(){
    return stock;
}

template <class R, R radius> Pie<R, radius>::Pie(const int initialStock) 
    : stock(initialStock){ 
    // is_integral pozwala na boole i chary, nie wiem czy powinien.
    assert((std::is_integral<R>::value));
    assert(initialStock >= 0);
}


template <class R, R radius> class CherryPie : public Pie<R, radius>{
    //public:
    //    CherryPie(int initialStock);
    using Pie<R, radius>::Pie;
};

/* ten konstruktor może być odziedziczony
template <class R, R radius> CherryPie<R, radius>::CherryPie(int initialStock) : Pie<R, radius>::Pie(initialStock){

}*/


template <class R, R radius, class P> class ApplePie : public Pie<R, radius>{
    private:
        P price;

    public:
        ApplePie(int initialStock, P price);
        void sell();
        P getPrice();
};

template <class R, R radius, class P> ApplePie<R, radius, P>::ApplePie(int initialStock, P price) 
    : Pie<R, radius>::Pie(initialStock){
    assert((std::is_floating_point<P>::value));
    this->price = price;
}

template <class R, R radius, class P> void ApplePie<R, radius, P>::sell(){
    assert((Pie<R, radius>::stock > 0));
    Pie<R, radius>::stock--;
}


template <class R, R radius, class P> P ApplePie<R, radius, P>::getPrice(){
    return price;
}

#endif // _PIE_
