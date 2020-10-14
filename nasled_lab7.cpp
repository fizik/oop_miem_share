#include <iostream>
using namespace std;

class Goods {}; 

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

Unit::Unit() :
    x(0), y(0), name("") { cout <<"Unit\n"; }
    
Unit::Unit(int _x, int _y, string _name) :
    x(_x), y(_y), name(_name) { cout <<"Unit3\n";  }

MilitaryUnit::MilitaryUnit() :
    health(0) { cout <<"MilitaryUnit\n"; }  

//правильный конструктор
// MilitaryUnit::MilitaryUnit(int _x, int _y, string _name) :
//     Unit(_x, _y, _name), health(0) { cout <<"MilitaryUnit3\n";  }

//неправильный конструктор
MilitaryUnit::MilitaryUnit(int _x, int _y, string _name) {
    cout <<"MilitaryUnit3\n";  
    Unit(_x, _y, _name);
    health=0;
}
    
MilitaryUnit::~MilitaryUnit() { }  
Unit::~Unit() {}
    
int main() {
    MilitaryUnit mu0;
    MilitaryUnit mu1(10, 10, "unit1");
    cout <<"done";
}
