#include <iostream>

using namespace std;

//example the interface is:
class MotorVehicle
{
public:
    virtual void run() const;// = 0
    virtual int getFuel() const = 0;
};

//And then the implementation is:
class Car : public MotorVehicle
{
    int fuel;

public:
    void run() const override
    {
        printf("Wrroooooooom\n");
    }


    int getFuel() const override
    {
        return this->fuel;
    }
};

int main() {
    Car car1;
    cout<<"fuel = " << car1.getFuel();
}
