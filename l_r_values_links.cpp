#include <iostream>

using namespace std;

int main() {
    int i=1;
    const int ci=2;
    
    int &lv1=i;
//  int &lv2=ci; //error
//  int &lv3=10; //error

    lv1=20;

    const int &clv1=i;
    const int &clv2=ci;
    const int &clv3=10;

//  clv1=20; //error
//  clv2=20; //error
//  clv3=20; //error


//  int &&rv1=i;  //error
//  int &&rv2=ci; //error
    int &&rv3=10;
    
    rv3=20;

//  const int &&crv1=i;  //error
//  const int &&crv2=ci; //error
    const int &&crv3=10;
    
//  crv3=20; //error
    

}
