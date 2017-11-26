#ifndef _CAKE_
#define _CAKE_

// BBP-Type Formula
constexpr double get_ln2(){
    long double res = 0, denom = 1;
    for (int i = 0; i < 100; i++){
        res += 1.0 / (2 * i + 1) / denom;
        denom *= 9;
    }
    return res * 2 / 3;
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
    static_assert(std::is_integral<T>::value, 
                  "Cake got wrong parameter: lenght type should be integral.");
    assert(initialStock >= 0);
}


template <class T, T length, T width> class CheeseCake 
    : public Cake<T, length, width>{
    using Cake<T, length, width>::Cake;
};


template <class T, T length, T width, class P> class CreamCake 
    : public Cake<T, length, width>{
    private:
        P price;

    public:
        CreamCake(int initialStock, P price);
        void sell();
        P getPrice();
};

template <class T, T length, T width, class P> 
    CreamCake<T, length, width, P>::CreamCake(int initialStock, P price) 
    : Cake<T, length, width>::Cake(initialStock){
    static_assert(std::is_floating_point<P>::value, 
                  "Cake got wrong parameter: price type should be floating point.");
    this->price = price;
}

template <class T, T length, T width, class P> void 
    CreamCake<T, length, width, P>::sell(){
    assert((Cake<T, length, width>::stock > 0));
    Cake<T, length, width>::stock--;
}

template <class T, T length, T width, class P> P 
    CreamCake<T, length, width, P>::getPrice(){
    return price;
}

#endif // _CAKE_
