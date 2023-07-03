#include <iostream>
#include <string>
#include <memory>


using namespace std;


struct IVehicle
{
    virtual void draw() const = 0;
};


class Vehicle : public IVehicle
{
public:
    Vehicle(const string &name) : name{name} {}

    void draw() const override { cout << name; }
protected:
    string name;
};


class Optional : public IVehicle
{
public:
    Optional(IVehicle *target) : target{target} {}

    void draw() const override { target->draw(); }

private:
    shared_ptr<IVehicle> target;
};


class SunRoof : public Optional
{
public:
    SunRoof(IVehicle *target) : Optional{target} {}
    void draw() const override
    {
        Optional::draw();
        cout << " with sunroof";
    }
};


class Hybrid : public Optional
{
public:
    Hybrid(IVehicle *target) : Optional{target} {}
    void draw() const override
    {
        Optional::draw();
        cout << " with hybrid engine";
    }
};


class LeatherSeats : public Optional
{
public:
    LeatherSeats(IVehicle *target) : Optional{target} {}
    void draw() const override
    {
        Optional::draw();
        cout << " with leather seats";
    }
};


class HeatedSeats : public Optional
{
public:
    HeatedSeats(IVehicle *target) : Optional{target} {}
    void draw() const override
    {
        Optional::draw();
        cout << " with heated seats";
    }
};


int main()
{
    auto dacia = Hybrid(new Vehicle("Dacia Logan"));
    auto volvo = LeatherSeats( new Hybrid (new SunRoof (new HeatedSeats (new Vehicle ("Volvo XC90")))) );

    dacia.draw(); cout << endl;
    volvo.draw(); cout << endl;

}