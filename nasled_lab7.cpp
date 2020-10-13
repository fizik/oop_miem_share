#include <iostream>
using namespace std;

class Goods {}; 

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


class Unit {
  public:
    Unit();
    Unit(int _x, int _y, string _name);
    ~Unit();  
    void move();
    void getPosition(int &_x, int &_y);
  private:
    int x, y;  
    string name;
};

class TradeUnit : Unit {
  public:
    TradeUnit();	
    ~TradeUnit();  
    TradeUnit(int _x, int _y, string _name);  
    void loadGoods(const Goods &gd);
    Goods unloadGoods(int pos);
    Goods getGoods(int pos);
    int getGoodsCount() {return goodsCount;}
  private:
    int goodsCount;
    Goods *storage;
};

class MilitaryUnit : Unit {
  public:
    MilitaryUnit();
    MilitaryUnit(int _x, int _y, string _name);
    ~MilitaryUnit();  
    void fight();
  private:
    int health;
    // И еще много свойств и методов.
};

class Stream {
  public:
    void save (int);  
    void load (int);  
    void save(double);  
    void load (double);
};

class NetworkStream : Stream {
  public:
    void save(int);
    void load(int);
    void save(double);
    void load(double);
    bool openConnection(string);
    bool closeConnection();
    // And so on.
};

class FileStream : Stream {
  public:
    void save(int);
    void load(int);
    void save(double);
    void load(double);
    bool openFile(string);
    bool closeFile();
    // And so on.
};

class Point {
  public:
    void setPosition(int _x, int _y);
    void getPosition(int &_x, int &_y);
  private:
    int x, y;
};

int main() {
    
}
