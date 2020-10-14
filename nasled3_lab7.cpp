#include <iostream>
using namespace std;

class Point {
  public:
    void setPosition(int _x, int _y) {};
    void getPosition(int &_x, int &_y) {};
  private:
    int x, y;
};

class Unit { 
  public:
    void move();
  private:
    Point pt;
};

int main() {
    Unit unit1;
    unit1.move();
}

void Unit::move() { };
