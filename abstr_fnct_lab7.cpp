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

class Chivalry : public MilitaryUnit {
  public:
    Chivalry() {
        // …
        kind=ukChivalry;
    };
    // …
    virtual void move() {cout<<"cmv\n";};
};


class Galley : public MilitaryUnit {
  public:
    Galley() {
        // …
        kind=ukGalley;
    };
    // …
    virtual void move() {cout<<"mmv\n";};
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
    TheGame game;
    game.moveAll();
}
