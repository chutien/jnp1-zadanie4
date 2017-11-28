#include<bits/stdc++.h>
#include "pie.h"
#include "cake.h"
//#include "bakery.h"

using namespace std;

string s = "hhhh";
    
void cake_test(){
    /*CheeseCake<long long, 5, 2> ciasto(5);
    cout << ciasto.getArea() << endl;
    
    CreamCake<int, 1, 1, double> krem(2, 3.21);
    cout << krem.getPrice() << endl;
    krem.sell();
    cout << krem.getStock() << endl;
    krem.sell();
    //krem.sell(); //OK - asertion failed
    cout << krem.getArea() << endl;*/
    
}

//void bakery_test(){
  /*
  CreamCake<int, 1, 1, double> krem(2, 3.21);
    CheeseCake<int, 5, 2> ciasto(5);
    CheeseCake<int, 5, 2> ciasto2(4);
    Bakery<double, int, 30, CreamCake<int, 1, 1, double>, CheeseCake<int, 5, 2> > piek(krem, ciasto);
    cout << piek.getProfits() << endl;
  */
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
   /* auto bakery = Bakery<
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
}*/

int main(){
    std::cout << std::setprecision(8) << std::fixed;
    CherryPie<int, 1> ciacho(6);
    cout << ciacho.getArea() << " " << ciacho.getStock() << endl;
    
    //CherryPie<int, 1> zle_ciacho(6, 12.3);
    
    //ApplePie<unsigned int, 100, int> jablko(2, 12); //OK - static_asertion failed, price must be floating point
   /* ApplePie<unsigned int, 100, double> jablko(2, 12.34);
    cout << jablko.getPrice() << endl;
    cout << jablko.getArea() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;*/
    //jablko.sell(); //OK - asertion failed
    
    //To powinno sie nie kompilowac
    //CherryPie<string*, &s> ciacho2(6);  //OK - static_asertion failed, radius must be integral
    CherryPie<int, 3> ciacho2(6);
    
    cake_test();
    //bakery_test();
    
    return 0;
}
