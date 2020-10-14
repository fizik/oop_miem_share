#include <iostream>
using namespace std;

class Point {
  public:
    void setPosition(int _x, int _y) {};
    void getPosition(int &_x, int &_y) {};
  private:
    int x, y;
};

class Unit : public Point {
  public:
    //…
};

int main() {
    Unit unit1;
    unit1.setPosition(-1, -1);
}
