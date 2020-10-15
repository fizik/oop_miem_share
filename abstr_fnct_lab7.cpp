
enum UnitKind {ukNone, ukChivalry, ukGalley /*, …*/};

class Unit {
  public:
    UnitKind getKind() { return kind; };  
    virtual void move()=0;
  private:  
    UnitKind kind;
};
// Наследуем от Unit класс MilitaryUnit,
//а  от него класс Chivalry и остальные
