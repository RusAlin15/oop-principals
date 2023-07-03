#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <thread>


using namespace std;


class observable;


struct observer
{
    virtual void update(observable *o) = 0;  // update(int data)
};


class observable  // subject
{
public:
    void attach(observer *obs)
    {
        if (find(observers.begin(), observers.end(), obs) == observers.end())
            observers.push_back(obs);
    }

    void detach(observer *obs)
    {
        observers.erase(
            remove_if(observers.begin(), observers.end(),
                      [obs](auto o){ return o = obs; })
        );
    }

    void notify()  // broadcast
    {
        for (auto obs : observers)
            obs->update(this);
    }

private:
    vector<observer*> observers;
};


class customer : public observer
{
public:
    customer(const string &name) : name{name} {}

    string getName() const { return name; }

    void update(observable *o) override;  // business logic

private:
    string name;
};


class iphone{};


class emag : public observable
{
public:
    static emag &inst()
    {
        static emag single;
        return single;
    }

    void buy(customer *c)
    {
        if (iphones.size() == 0) {
            cout << c->getName() << " cannot buy\n";
            attach(c);
        } else {
            cout << c->getName() << " bought one iphone\n";
            detach(c);
            iphones.pop_back();
        }
    }

    void add(const iphone &phone)
    {
        iphones.push_back(phone);
        notify();  // in fiecare setter notific toti observerii
    }

private:
    vector<iphone> iphones;

    emag() {}
    emag(const emag &o) = delete;
};


class marketing_campaign : public observer
{
public:
    void update(observable *o)
    {
        cout << "Au aparut noile telefoane iphone\n";
    }
};


void customer::update(observable *o)
{
    emag *e = (emag*) o;

    if (e != nullptr) {
        e->buy(this);
    }
}


int main()
{
    marketing_campaign c;
    emag::inst().attach(&c);

    customer ion{"Ion"};
    emag::inst().buy(&ion);

    this_thread::sleep_for(2s);

    emag::inst().add(iphone());
}