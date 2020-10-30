#include <iostream>

using namespace std;

class Int {
    int a;  
  public:
    int getA() const { return a; };
    Int& operator=(const int &o);
    Int operator+(const Int &o);
};

Int& Int::operator=(const int &o) {
    a=o%10+o/10*16;
    return *this;
}

Int Int::operator+(const Int &o) {
    Int tmp(*this);  
    tmp.a+=o.a;
    return tmp;
}

ostream& operator<<(ostream &os, const Int &dt) {
    char ab[]="0123456789ABCDEF";
    os << dt.getA()/16<<ab[dt.getA()%16];
    return os;
}

int main() {
    Int x, y, z;
    x=19;
    y=29;
    z=x+y;

    cout << "Sum of " << x << " + " << y << " = " << z << "\n";
}
