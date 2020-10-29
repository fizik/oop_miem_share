#include <iostream>
using namespace std;

struct A {
    virtual void some_func();  
    virtual void f(int);  
    virtual void g() const;
};

struct B : public A {
    virtual void f(long) override;  // Ошибка: несоответствие типа парам. 
    virtual void f(int) override;   // OK
    virtual int  g(int) override;   // Ошибка: несоответствие возв. типа
    virtual void g() const final;   // OK
    virtual void g(long);           // OK: новая виртуальная функция
    void sone_func() override; // Ошибка: неверное имя функции 
};

struct C : B {
    virtual void g() const; // Ошибка: замещение финальной функции
};

struct F final {
    int x, y;
};

struct D : F { // Ошибка: наследование от final классов запрещено
    int z;
};

int main() {
}
