#include<bits/stdc++.h>

#include "bakery.h"
#include "cake.h"
#include "pie.h"
using namespace std;

string s = "hhhh";
    
void cake_test(){
    CheeseCake<long long, 5, 2> ciasto(5);
    cout << ciasto.getArea() << endl;
    
    CreamCake<int, 1, 1, double> krem(2, 3.21);
    cout << krem.getPrice() << endl;
    krem.sell();
    cout << krem.getStock() << endl;
    krem.sell();
    //krem.sell(); //OK - asertion failed
    cout << krem.getArea() << endl;
    
}

void bakery_test(){
  
  CreamCake<int, 1, 1, double> krem(2, 3.21);
    CheeseCake<int, 5, 2> ciasto(5);
    CheeseCake<int, 5, 2> ciasto2(4);
    Bakery<double, int, 30, CreamCake<int, 1, 1, double>, CheeseCake<int, 5, 2> > piek(krem, ciasto);
    cout << piek.getProfits() << endl;
    
    piek.sell< CreamCake<int, 1, 1, double> >();
    //piek.sell< CreamCake<int, 1, 155, double> >(); // OK, CE: no matching function
    //piek.sell< CheeseCake<int, 5, 2> >(); // OK, CE: no matching function
    cout << piek.getProfits() << endl;
    piek.sell< CreamCake<int, 1, 1, double> >();
    cout << piek.getProfits() << endl;
    piek.sell< CreamCake<int, 1, 1, double> >();
    cout << piek.getProfits() << endl; //wynik sie nie zmienia: ok, juz nie ma co sprzedawać
    cout << piek.getProductStock< CreamCake<int, 1, 1, double> >() << endl;
    //cout << piek.getProductStock< CreamCake<long long, 1, 1, double> >() << endl; // OK, CE: no matching function
    
    //Bakery<double, int, 30, CreamCake<int, 1, 1, double>, CheeseCake<int, 5, 2>, CheeseCake<int, 5, 2> > nieunikatowa_piekarnia(krem, ciasto, ciasto2);
    //auto bakery4 = Bakery<float, int, 10, CherryPie<int, 1>, CherryPie<int, 1> >(CherryPie<int, 1>(3), CherryPie<int, 1>(4)); //
    //
  /*
    auto bakery7 = Bakery<
              double, 
              int,
              10,
              ApplePie<int, 1, float>
          >(
              ApplePie<int, 1, float>(3, 1.4f)
          );
  */ // OK, inne typy cen (z bakery_example)
    
    auto bakery = Bakery<
      float,
      int,
      30,
      CherryPie <int, 1>,
      ApplePie<int, 1, float>,
      ApplePie<int, 2, float>,
      CheeseCake<int, 2, 3>
      >(
        CherryPie<int, 1>(3),
        ApplePie<int, 1, float>(3, 2.4f),
        ApplePie<int, 2, float>(2, 4.5f),
        CheeseCake<int, 2, 3>(3)
        );
    bakery.restock<ApplePie<int, 1, float>>(1);
    //bakery.restock<CherryPie<int, 1>>(42); //OK - static assertion is apple pie failed
    //bakery.restock<CheeseCake<int, 2, 3>>(100) //OK - static assertion is apple pie failed
    
    //Bakery<float, int, 10, CherryPie<int, 1>, CherryPie<int, 1>>(CherryPie<int, 1>(3), CherryPie<int, 1>(4));
}

void unique_test() {
    auto bakery = Bakery<float, int, 1000,
            CherryPie<int, 1>, CherryPie<int, 2>, CherryPie<int, 3>, CherryPie<int, 4>, CherryPie<int, 5>,
            ApplePie<int, 1, float>, ApplePie<int, 2, float>, ApplePie<int, 3, float>, ApplePie<int, 4, float>, ApplePie<int, 5, float>,
            CheeseCake<int, 1, 1>, CheeseCake<int, 2, 2>, CheeseCake<int, 3, 3>, CheeseCake<int, 4, 4>, CheeseCake<int, 5, 5>, /*Pie<int, 1, float>,*/
            CreamCake<int, 1, 1, float>, CreamCake<int, 2, 2, float>, CreamCake<int, 3, 3, float>, CreamCake<int, 4, 4, float>, CreamCake<int, 5, 5, float>
            >(
            CherryPie<int, 1>(1), CherryPie<int, 2>(1), CherryPie<int, 3>(1), CherryPie<int, 4>(1), CherryPie<int, 5>(1),
            ApplePie<int, 1, float>(1, 1.5f), ApplePie<int, 2, float>(1, 1.5f), ApplePie<int, 3, float>(1, 1.5f), ApplePie<int, 4, float>(1, 1.5f), ApplePie<int, 5, float>(1, 1.5f),
            CheeseCake<int, 1, 1>(1), CheeseCake<int, 2, 2>(1), CheeseCake<int, 3, 3>(1), CheeseCake<int, 4, 4>(1), CheeseCake<int, 5, 5>(1), /*Pie<int, 1, float>(1, 1.5f),*/
            CreamCake<int, 1, 1, float>(1, 1.5f), CreamCake<int, 2, 2, float>(1, 1.5f), CreamCake<int, 3, 3, float>(1, 1.5f), CreamCake<int, 4, 4, float>(1, 1.5f), CreamCake<int, 5, 5, float>(1, 1.5f)
    );
    //auto bakery1 = Bakery<float, int, 1, CherryPie<int, 1>(); //Ok - nie kompiluje sie
    //auto appl = Cake<unsigned int, 100, 50, double>();

}
/*
int main(){
    std::cout << std::setprecision(8) << std::fixed;
    CherryPie<int, 1> ciacho(6);
    //ciacho.restock(5); OK - cherrypie ma nie miec restock;
    cout << ciacho.getArea() << " " << ciacho.getStock() << endl;
    // cout << ciacho.getPrice() << endl; //OK - template argument deduction/substitution failed
    //CherryPie<int, 1> zle_ciacho(6, 12.3);
    
    //ApplePie<unsigned int, 100, int> jablko(2, 12); //OK - static_asertion failed, price must be floating point
    ApplePie<unsigned int, 100, double> jablko(2, 12.3);
    cout << jablko.getPrice() << endl;
    cout << jablko.getArea() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;
    jablko.sell();
    jablko.restock(1);
    cout << jablko.getStock() << endl;
    //jablko.sell(); //OK - asertion failed
    
    //To powinno sie nie kompilowac
    //CherryPie<string*, &s> ciacho2(6);  //OK - static_asertion failed, radius must be integral
    CherryPie<int, 3> ciacho2(6);
    //ciacho2.sell(); // OK - CE: no matching function
    
    cake_test();
    bakery_test();
    unique_test();
    return 0;
}
*/