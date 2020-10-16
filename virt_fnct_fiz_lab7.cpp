#include <iostream>
using namespace std;

class Goods {}; 

class Unit {
  public:
    Unit();
    ~Unit();
    virtual void move();
    // ...
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

class MilitaryUnit : public Unit { 
  public:  
    MilitaryUnit();
    ~MilitaryUnit();  
    virtual void move();
};

class Chivalry : public MilitaryUnit {
  public:
    Chivalry();
    ~Chivalry();
    virtual void move();
};

Unit::Unit() { cout <<"Unit\n"; }
Unit::~Unit() { cout <<"~Unit\n"; }

MilitaryUnit::MilitaryUnit() { cout <<"MilitaryUnit\n";  }
MilitaryUnit::~MilitaryUnit() {  cout <<"~MilitaryUnit\n"; }  
    
TradeUnit::TradeUnit() {
    cout<<"TradeUnit\n";
    storage = new Goods[5]; // буфер
    goodsCount=0;
};

TradeUnit::~TradeUnit() {
    cout<<"~TradeUnit\n";
    delete [] storage;
};

Chivalry::Chivalry() { cout <<"Chivalry\n";  }
Chivalry::~Chivalry() { cout <<"~Chivalry\n";  }

void Unit::move() { cout <<"Unit::move\n"; }
void TradeUnit::move() { cout <<"TradeUnit::move\n"; }
void MilitaryUnit::move() { cout <<"MilitaryUnit::move\n"; }
void Chivalry::move() { cout <<"Chivalry::move\n"; }

int oldmain() {
    // чтобы каждый объект вел себя
    // корректно, надо знать его тип.    
    Unit *un=new Unit;
    TradeUnit *tun=new TradeUnit;
    Chivalry *ch=new Chivalry;
   
    un->move();
    tun->move();
    ch->move();
    // И так далее...
        
    delete un;
    delete tun;
    delete ch;
    // И так далее...
    return 0;
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

    // oldmain() ;
    // return 0;
}
