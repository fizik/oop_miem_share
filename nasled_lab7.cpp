#include <iostream>
using namespace std;

class First { // Базовый класс.
  public:
    int a, b;  
    void f1();
};

class Second: First { // Second наследуется от  First.
  public:
    double c, d;  
    int f2();
}; // Теперь у него есть 4 свойства и 2 метода.


