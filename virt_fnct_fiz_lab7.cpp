#include <iostream>
using namespace std;

class Goods {}; 

class Unit {
  public:
    Unit();
    ~Unit();  
    virtual void move();
};

class TradeUnit : public Unit {
  public:
    TradeUnit();	
    ~TradeUnit();
    virtual void move();
  private:
    int goodsCount;
    Goods *storage;
};

class MilitaryUnit : public Unit { // Так лучше
  public:  
    MilitaryUnit();
    ~MilitaryUnit();  
    virtual void move();
};

class Chivalry : public MilitaryUnit {
  public:
    Chivalry();
    virtual void move();
};

TradeUnit::TradeUnit() {
    cout<<"TradeUnit\n";
    storage = new Goods[5]; // буфер
    goodsCount=0;
};

TradeUnit::~TradeUnit() {
    cout<<"~TradeUnit\n";
    delete [] storage;
};

void TradeUnit::move() {
    cout <<"TradeUnit::move\n";
}

Chivalry::Chivalry() { cout <<"Chivalry\n";  }

Unit::Unit() { cout <<"Unit\n"; }
Unit::~Unit() { cout <<"~Unit\n"; }
    
MilitaryUnit::MilitaryUnit() { cout <<"MilitaryUnit\n";  }
MilitaryUnit::~MilitaryUnit() {  cout <<"~MilitaryUnit\n"; }  

void Unit::move() {
    cout <<"Unit::move\n";
}

// Поведение войск несколько иное.
void MilitaryUnit::move() {
    cout <<"MilitaryUnit::move\n";
}

void Chivalry::move() {
    cout <<"Chivalry::move\n";
}

int main() {
    Unit *units[]= {
        new Unit,
        new TradeUnit,
        new Chivalry
    }; //   ^^^ Это корректное преобразование типов

    for( auto i=0; i<sizeof(units)/sizeof(*units); i++ )
        units[i]->move();// Корректно передвигает разные классы
        
    for( auto i=0; i<sizeof(units)/sizeof(*units); i++ )
        delete units[i]; // Можем не задумываться о типах
        
    cout<<"sizeof(units)="<<sizeof(units)<<"\n";
    cout<<"sizeof(*units)="<<sizeof(*units)<<"\n";
}
