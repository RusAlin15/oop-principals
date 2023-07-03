#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;


class singleton
{
public:
    static singleton *getInstance()
    {
        singleton *inst = SINGLE;  // LOCAL variable
        if (inst == nullptr) {
            cout << "me too\n";
            mut.lock();
            inst = SINGLE;  // RAM

            if (inst == nullptr) {  // double checking
                cout << "only me\n";
                SINGLE = new singleton{100};
                inst = SINGLE;
            }

            mut.unlock();
        }
        return inst;
    }

    // copy ctor
    singleton(const singleton &other) = delete;

    int getX() const { return x; }

private:
    int x;

    static singleton *SINGLE;  // 8 bytes
    static mutex mut;

    singleton(int x) : x{x}
    {
        cout << "ctor\n";
    }
};


singleton *singleton::SINGLE{nullptr};
mutex singleton::mut{};


int main()
{

    vector<thread> workers;
    for (int i = 0; i < 20; i++)
        workers.emplace_back(thread([](){ cout << singleton::getInstance()->getX() << endl; }));

    for (auto &w : workers)
        w.join();
}