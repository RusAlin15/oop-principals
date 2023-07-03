#include <iostream>

using namespace std;


class payment_method
{
public:
    virtual void show_payment_info() const = 0;
};


class shopping_framework
{
public:
    void connect_to_bank()
    {
        cout << "Connected to bank\n";
    }

    virtual payment_method &get_payment_method() = 0;

    void buy(double sum, const string &item)
    {
        cout << "Buying item " << item << endl;
        auto &method = get_payment_method();
        method.show_payment_info();
        connect_to_bank();
        cout << "OK\n";
    }
    // ...
};


class my_payment_method : public payment_method
{
public:
    void show_payment_info() const override { cout << "This is my payment method\n"; }
};


class my_shop: public shopping_framework
{
public:
    payment_method &get_payment_method() override
    {
        static my_payment_method m;
        return m;
    }
};


int main()
{
    my_shop edocti;
    edocti.buy(1000, "telefon");
}