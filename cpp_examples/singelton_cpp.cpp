#include <iostream>
#include <thread>
#include <vector>

using namespace std;


class singleton
{
public:
    static singleton INST;  // eager instantiation

    static const int MAX;  // irelevant pt pattern


    static singleton &getInstance()
    {
        static singleton single{10};  // apelata o sg data; ATOMIC!! lazy instantiation
        return single;  // de fiecare data
    }

    // copy ctor
    singleton(const singleton &other) = delete;

    int getX() const { return x; }

private:
    int x;

    singleton(int x) : x{x}
    {
        cout << "ctor\n";
    }
};


const int singleton::MAX{100};
singleton singleton::INST{singleton::MAX};


void sayhello()
{
    cout << "Hello from thread " << this_thread::get_id() << endl;
    this_thread::sleep_for(2s);
}


int main()
{
    /*
    singleton &s1 = singleton::getInstance();
    singleton &s2 = singleton::getInstance();

    cout << &s1 << endl;
    cout << &s2 << endl;

    thread t(sayhello);
    t.join();  // asteapta copilul
    cout << "mergi mai departe\n";


    vector<thread> workers;
    for (int i = 0; i < 20; i++)
        workers.emplace_back(thread([](){ cout << singleton::getInstance().getX() << endl; }));

    for (auto &w : workers)
        w.join();
    */

    //singleton::INST.getX();

}