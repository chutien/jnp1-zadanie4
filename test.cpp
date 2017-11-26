#include<bits/stdc++.h>
#include "pie.h"
#include "cake.h"

using namespace std;

string s = "hhhh";
    
void cake_test(){
    Cake<long long, 5, 2> ciasto(5);
    cout << ciasto.getArea() << endl;
}

int main(){
    std::cout << std::setprecision(8) << std::fixed;
    CherryPie<int, 1> ciacho(6);
    cout << ciacho.getArea() << " " << ciacho.getStock() << endl;
    
    //ApplePie<unsigned int, 100, int> jablko(2, 12); //OK - static_asertion failed, price must be floating point
    ApplePie<unsigned int, 100, double> jablko(2, 12.34);
    cout << jablko.getPrice() << endl;
    cout << jablko.getArea() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;
    //jablko.sell(); //OK - asertion failed
    
    //To powinno sie nie kompilowac
    //CherryPie<string*, &s> ciacho2(6);  //OK - static_asertion failed, radius must be integral
    CherryPie<int, 3> ciacho2(6);
    
    cake_test();
    
    return 0;
}