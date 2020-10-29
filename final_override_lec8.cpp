#include <iostream>
using namespace std;

struct B {
    virtual void some_func();  
    virtual void f(int);  
    virtual void g() const;
};

struct D1 : public B {
    void f(int) override; // OK
    virtual void g() const final; // OK
    virtual void g(long); // OK: новая виртуальная функция
};

#if 0
struct Wrong : public B {
    void sone_func() override; //Ошибка: неверное имя функции 
    virtual void f(long) override; //Ошибка: несоответствие типа 
    virtual int f(int) override;//Ошибка: несоответствие возв. типа
};

struct D2 : D1 {
    virtual void g() const; //Ошибка: замещение финальной функции
};
#endif


int main() {
}
