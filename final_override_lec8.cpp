#include <iostream>
using namespace std;

struct A {
    virtual void some_func();  
    virtual void f(int);  
    virtual void g() const;
};

struct B : public A {
    void f(int) override; // OK
    virtual void g() const final; // OK
    virtual void g(long); // OK: новая виртуальная функция
};

#if Wrong
struct C : public A {
    void sone_func() override; //Ошибка: неверное имя функции 
    virtual void f(long) override; //Ошибка: несоответствие типа 
    virtual int f(int) override;//Ошибка: несоответствие возв. типа
};

struct D : B {
    virtual void g() const; //Ошибка: замещение финальной функции
};
#endif


int main() {
}
