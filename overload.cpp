#include <iostream>

using namespace std;

typedef int Int;

#if ForSlide
class MyClass {
    int a;  
  public:
    MyClass();
    MyClass(int d) { a=d; };
    MyClass& operator+=(const MyClass &obj);  
    int getA() const { return a; };
};
#endif

class MyClass {
    int a;  
  public:
    MyClass();
    MyClass(int d) { a=d; };
    MyClass& operator+=(const MyClass &obj);  
    MyClass& operator-=(const MyClass &obj);  
    int getA() const { return a; };
    
    MyClass& operator = (const MyClass &obj);
//    MyClass operator = (const MyClass &obj);

    MyClass operator + (const MyClass &obj);
    MyClass operator - ();
    MyClass& operator -- ();
    MyClass operator -- (int);


    MyClass operator + (const float &obj); //debug    
};

MyClass& MyClass::operator += (const MyClass &obj) {
    a+=obj.getA();
    cout << "+=\n";
    return *this;
}

MyClass& MyClass::operator=(const MyClass &obj) {
    // some code here  
    a=obj.getA();
    return *this;
}

MyClass MyClass::operator+ (const MyClass &obj) {
    MyClass tmp(*this);  
    tmp+=obj;
    return tmp;
}

MyClass MyClass::operator+(const float&obj) {
    return *this+=obj;
}

MyClass MyClass::operator - () { // Unary minus.
    MyClass tmp(-a);  
    return tmp;
}

MyClass& MyClass::operator -- () { // Prefix form
    a--;
    return *this;
}

MyClass MyClass::operator -- (int) { // Postfix form
    MyClass b(a);
    a--;
    return b;
}


MyClass& MyClass::operator -= (const MyClass &obj) {
    a-=obj.getA();
    cout << "-=\n";
    return *this;
}


// This function don’t belong to any class.
MyClass operator - (const MyClass &o1,  const MyClass &o2) {
    MyClass tmp(o1);  
    return tmp=tmp-o2;
}


int main() {
    MyClass a(1), b(2);  
    a+=b;
    cout << "a=" << a.getA() <<"\n";
    
    MyClass c(4);
    a=b=c;
    
    cout << "a=" << a.getA() <<"\n";


    Int x, y, z;
    x=19;
    y=29;
    z=x+y;

    cout << "Sum of " << x << " + " << y << " = " << z << "\n";
    
    //a += b + c - d;
    MyClass d(4);
    
    MyClass tmp1(b);  
    tmp1 += c;
    MyClass tmp2(tmp1);  
    tmp1.~MyClass();  
    MyClass tmp3(tmp2);  
    tmp3 -= d;
    MyClass tmp4(tmp3);  
    tmp3.~MyClass();  
    tmp2.~MyClass();
    a += tmp4;  
    tmp4.~MyClass();
}
