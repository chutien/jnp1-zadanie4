#include<bits/stdc++.h>
#include "pie.h"

using namespace std;

string s = "hhhh";
    
int main(){
    CherryPie<int, 10> ciacho(6);
    cout << ciacho.getArea() << " " << ciacho.getStock() << endl;
    
    //ApplePie<unsigned int, 100, int> jablko(2, 12); //OK - asertion failed, price must be floating point
    ApplePie<unsigned int, 100, double> jablko(2, 12.34);
    cout << jablko.getPrice() << endl;
    cout << jablko.getArea() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;
    //jablko.sell(); //OK - asertion failed
    
    //To powinno sie nie kompilowac
    //CherryPie<string*, &s> ciacho2(6);  //OK - asertion failed, radius must be integral
    CherryPie<int, 3> ciacho2(6);
    return 0;
}