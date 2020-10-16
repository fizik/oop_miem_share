#include <iostream>
using namespace std;

class Unit {
  public:
    Unit();
    Unit(int _x, int _y, string _name);
    ~Unit();  
    virtual void move();
    void getPosition(int &_x, int &_y);
  private:
    int x, y;  
    string name;
};

class Unit2 {
    // some code
    virtual void move();
    // more code
};

class Goods {}; 

class TradeUnit : public Unit {
  public:
    TradeUnit();	
    ~TradeUnit();  
    TradeUnit(int _x, int _y, string _name);  
    void loadGoods(const Goods &gd);
    Goods unloadGoods(int pos);
    Goods getGoods(int pos);
    int getGoodsCount() {return goodsCount;}
    virtual void move();
  private:
    int goodsCount;
    Goods *storage;
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

enum Torders {others, guard};

class MilitaryUnit : public Unit { // Так лучше
  public:  
    MilitaryUnit();
    MilitaryUnit(int _x, int _y, string _name);
    ~MilitaryUnit();  
    void fight();
    virtual void move();
  protected: // Так лучше 
    int health;
    Torders orders;
    void init();
    // И еще много свойств и методов.
};

class MilitaryUnit2 : public Unit {
  public:  
    // Будет сделана реализация
    virtual void move();
};

class Chivalry : public MilitaryUnit {
  public:  
    // …
    Chivalry();
    virtual void move();
    // Везде надо писать virtual
};

Chivalry::Chivalry() { cout <<"Chivalry\n";  }

Unit::Unit() :
    x(0), y(0), name("") { cout <<"Unit\n"; }
    
Unit::Unit(int _x, int _y, string _name) :
    x(_x), y(_y), name(_name) { cout <<"Unit3\n";  }

//самый правильный конструктор
MilitaryUnit::MilitaryUnit() { init();  cout <<"MilitaryUnit\n";  }
MilitaryUnit::MilitaryUnit(int _x, int _y, string _name) :
    Unit(_x, _y, _name) { init(); }
void MilitaryUnit::init() { health=0; } // Так лучше

MilitaryUnit::~MilitaryUnit() {  cout <<"~MilitaryUnit\n"; }  
Unit::~Unit() { cout <<"~Unit\n"; }

void Unit::move() {
    // Обычный юнит не передвигается
    cout <<"Unit::move\n";
}

// Поведение войск несколько иное.
void MilitaryUnit::move() {
    switch(orders) {
        case guard: // Stay here
        ; // And so on
    }
    cout <<"MilitaryUnit::move\n";
}

void Chivalry::move() {
    cout <<"Chivalry::move\n";
}

class Battleship : MilitaryUnit {};

class TheGame1 {
  private:
    // чтобы каждый объект вел себя
    // корректно, надо знать его тип.
    Battleship *btlships;  
    int bshipCount;  
    Chivalry *chivs;
    int ChCount;
    // И так несколько раз.
};

class TheGame {
  public:  
    void moveAll();
  private:
    // Сейчас для каждого объекта будет вызываться
    // правильный move.
    Unit **allUnits; // Именно массив указателей
    int unitsCount;
};

void TheGame::moveAll() {
    for( int i=0; i<unitsCount; i++ )
        allUnits[i]->move(); // Разберутся.
}


int main() {
    Unit *units[]= {
        new Unit,
        new TradeUnit,
        new Chivalry
    };

    for( auto i=0; i<sizeof(units)/sizeof(*units); i++ )
        units[i]->move();// Корректно передвигает разные классы
        
    for( auto i=0; i<sizeof(units)/sizeof(*units); i++ )
        delete units[i]; // Можем не задумываться о типах
        
    cout<<"sizeof(units)="<<sizeof(units)<<"\n";
    cout<<"sizeof(*units)="<<sizeof(*units)<<"\n";
}

#if 0
int main() {
    Unit unit;
    Chivalry *chiv=new Chivalry;
    chiv->move(); // Корректно передвигает
    unit.move();  // Обычный юнит не передвигает
    ((Unit*) chiv)->move(); // Корректно передвигает
    //^^^^^ Это корректное преобразование типов
    //((Unit*) chiv)->Chivalry::move(); //error: ‘Chivalry’ is not a base of ‘Unit’
    // Всё равно передвигает
    return 0;
}

int main0() {
    TheGame game;
    game.moveAll();
}
    
void main1() {
    Unit unit;
    MilitaryUnit *munit=new MilitaryUnit;

    munit->move(); // Корректно передвигает
    unit.move(); // Обычный юнит не передвигается 
    ((Unit*)munit)->move(); // Аналогично.
    //^^^^^Корректное преобразование типов.
}

void main2() {
    //MilitaryUnit mu0;
    MilitaryUnit mu1(10, 10, "unit1");
    cout <<"done";
}

void main3() {
    MilitaryUnit *munit=new MilitaryUnit;  
    Unit *unit=munit;
    
    munit->move(); // Корректно передвигает 
    unit->move(); // Обычный юнит не передвигается 
    ((MilitaryUnit *)unit)->move(); // Передвигает юнит
    //^^^^^Корректное преобразование типов.
}
#endif
