#include <iostream>

using namespace std;

struct AmericanSocket;

struct AmericanPlug
{
    void plug(AmericanSocket &s);
};

struct AmericanSocket
{
    void accept(AmericanPlug &p);
};

struct AmericanSmartPhone
{
    AmericanSmartPhone(const string &name) : name{name} {}
    void charge(AmericanSocket &s) { cout << "Charging...\n"; s.accept(plug); }

private:
    string name;
    AmericanPlug plug;
};

void AmericanPlug::plug(AmericanSocket &s) { s.accept(*this); }
void AmericanSocket::accept(AmericanPlug &p) { cout << "American plug inserted\n"; }


struct RomanianSocket;

struct RomanianPlug
{
    void plug(RomanianSocket &s);
};

struct RomanianSocket
{
    void accept(RomanianPlug &p);
};

void RomanianPlug::plug(RomanianSocket &s) { s.accept(*this); }
void RomanianSocket::accept(RomanianPlug &p) { cout << "Romanian plug inserted\n"; }


// Object adapter (composition)
class RomanianToAmericanAdapter
{
public:
    AmericanSocket getSocket() const { return socket; }
    void plug(RomanianSocket &s) { s.accept(rom_plug); }

private:
    AmericanSocket socket;
    RomanianPlug rom_plug;
};


int main()
{
    AmericanSmartPhone iphone{"14"};
    RomanianSocket wall_socket;

    RomanianToAmericanAdapter adapter;

    adapter.plug(wall_socket);
    AmericanSocket s = adapter.getSocket();
    iphone.charge(s);
}