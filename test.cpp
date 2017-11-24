#include<bits/stdc++.h>
#include "pie.h"

using namespace std;

int main(){
    CherryPie<int, 10> ciacho(6);
    cout << ciacho.getArea() << " " << ciacho.getStock() << endl;
    
    ApplePie<int, 100, double> jablko(2, 12.34);
    cout << jablko.getPrice() << endl;
    cout << jablko.getArea() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;
    jablko.sell();
    cout << jablko.getStock() << endl;
    //jablko.sell(); //OK - asertion failed
    
    //To powinno sie nie kompilowac
    CherryPie<char, 'h'> ciacho2(6);
    cout << ciacho2.getArea() << endl;
    return 0;
}