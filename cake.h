#ifndef _CAKE_
#define _CAKE_

// TODO liczyc ln 2
constexpr double get_ln2(){
    long double res = 0.693;
    return (res);
}

template <class T, T length, T width> class Cake {
    protected:
        static constexpr long double ln2 = get_ln2();
        int stock;
    
    public:
        explicit Cake(int initialStock);
        static double getArea();
        int getStock();
};

template <class T, T length, T width> double Cake<T, length, width>::getArea(){
    return length * width * ln2;
}


template <class T, T length, T width> int Cake<T, length, width>::getStock(){
    return stock;
}

template <class T, T length, T width> 
    Cake<T, length, width>::Cake(const int initialStock) : stock(initialStock){ 
    // is_integral pozwala na boole i chary, nie wiem czy powinien.
    assert((std::is_integral<T>::value));
    assert(initialStock >= 0);
}


template <class T, T length, T width> class CheeseCake : public Cake<T, length, width>{
    using Cake<T, length, width>::Cake;
};


/*template <class R, R radius, class P> class ApplePie : public Pie<R, radius>{
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
}*/

#endif // _CAKE_
