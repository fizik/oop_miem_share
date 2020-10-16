#include <iostream>
using namespace std;

class Goods {}; 


enum UnitKind {ukNone, ukChivalry, ukGalley /*, …*/};

class Unit {
  public:
    UnitKind getKind() { return kind; };  
    virtual void move()=0;
  protected:  
    UnitKind kind;
};
// Наследуем от Unit класс MilitaryUnit,
//а от него класс Chivalry и остальные

enum Torders {others, guard};

class MilitaryUnit : public Unit { // Так лучше
  public:  
    MilitaryUnit();
//    MilitaryUnit(int _x, int _y, string _name);
    ~MilitaryUnit();  
    void fight();
   // virtual void move();
  protected: // Так лучше 
    int health;
    Torders orders;
    void init();
    // И еще много свойств и методов.
};

class Chivalry : public MilitaryUnit {
  public:
    Chivalry() {
        // …
        kind=ukChivalry;
    };
    // …
    virtual void move() {cout<<"cmv\n";}; // реализация абстрактной ф-ции
};


class Galley : public MilitaryUnit {
  public:
    Galley() {
        // …
        kind=ukGalley;
    };
    // …
    virtual void move() {cout<<"mmv\n";}; // реализация абстрактной ф-ции
};


MilitaryUnit::MilitaryUnit() {};
MilitaryUnit::~MilitaryUnit() {};

//class Galley: public Chivalry {};
class TradeCart: public Chivalry {};


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
    Chivalry chl;
    Galley gal;
    //Unit un; 
    // error: cannot declare variable ‘un’ to be of abstract type ‘Unit’
}

#if 0

int main() {
    TheGame game;
    game.moveAll();
}

int main() {
    int unitCount=3;
    Unit *units[unitCount]= {
        new Galley,
        new Chivalry,
        new TradeCart
    };
    //    …
    for( int i=0; i<unitCount; i++ )
        delete units[i]; //Don’t care for type.
}


int main2() {
    int unitCount=3;
    Unit **units;
    units=new Unit*[unitCount];
    units[0]=new Galley;
    units[1]=new Chivalry;
    units[2]=new TradeCart;
    //    …
    for( int i=0;i<unitCount; i++ )
    delete units[i]; //Don’t care for type.
    delete [] units;
}
#endif
