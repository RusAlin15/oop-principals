#include <iostream>

using namespace std;


struct base
{s
    virtual void op1(int a) = 0;
    virtual void op2() = 0;
};


class target : public base
{
public:
    void op1(int a) override
    {
        cout << "t::op1(" << a << ")\n";
    }

    void op2() override
    {
        cout << "t::op2()\n";
    }

};s