#include <iostream>

using namespace std;


class driving_mode
{
public:
    virtual void steer(int angle) = 0;
    virtual void brake() = 0;
    virtual void accelerate(int d) = 0;
};


class vehicle
{
public:
    vehicle(driving_mode *dm) : dm{dm} {}

    virtual void steer(int angle)
    {
        dm->steer(angle);
    }

    virtual void brake()
    {
        dm->brake();
    }

    virtual void accelerate(int d)
    {
        dm->accelerate(d);
    }

    void set_driving_mode(driving_mode *d) { if (d) dm = d; }

private:
    driving_mode *dm;
    int speed{};
    int direction{};
};


class sports_mode : public driving_mode
{
public:
    static sports_mode &instance()
    {
        static sports_mode inst;
        return inst;
    }

    virtual void steer(int angle)
    {
        cout << "sport steering\n";
    }

    virtual void brake()
    {
        cout << "sports braking\n";
    }

    virtual void accelerate(int d)
    {
        cout << "sports accelerating\n";
    }

private:
    sports_mode() {}
    sports_mode(const sports_mode &o) = delete;
};


class comfort_mode : public driving_mode
{
public:
    static comfort_mode &instance()
    {
        static comfort_mode inst;
        return inst;
    }

    virtual void steer(int angle)
    {
        cout << "comf steering\n";
    }

    virtual void brake()
    {
        cout << "comf braking\n";
    }

    virtual void accelerate(int d)
    {
        cout << "comf accelerating\n";
    }

private:
    comfort_mode() {}
    comfort_mode(const comfort_mode &o) = delete;
};


int main()
{
    vehicle honda{&sports_mode::instance()};
    honda.accelerate(100);
    honda.brake();

    honda.set_driving_mode(&comfort_mode::instance());
    honda.accelerate(100);
    honda.brake();
}