#include <iostream>
using namespace std;

class Point {
  public:
    void setPosition(int _x, int _y) {};
    void getPosition(int &_x, int &_y) {};
  private:
    int x, y;
};

class Unit : Point {
  public:
    //…
};

int main() {
    int x,y;
    Unit unit1;
    unit1.getPosition(x, y);
}
