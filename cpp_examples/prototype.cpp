#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <sstream>


using namespace std;


class node2d
{
public:
    node2d(int x, int y, const string &name) :
        x{x}, y{y}, name{name} {}

    // node2d(const node2d &o) : x{o.x}, y{o.y}, name{o.name} {}

    node2d() {}

    virtual node2d *clone() const
    {
        node2d *inst = new node2d(x, y, name);
        return inst;
    }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setName(const string &name) { this->name = name; }

    friend ostream &operator<<(ostream &out, const node2d &n)
    {
        out << n.name << " (" << n.x << ", " << n.y << ")";
        return out;
    }

protected:
    int x;
    int y;
    string name;
};


class texture{};
class sound{};


class personaj : public node2d
{
public:
    personaj(int x, int y, const string &name) : node2d(x, y, name)
    {
        load_sound();
        load_texture();
    }

    personaj() : node2d() {}

    node2d *clone() const override
    {
        auto *c = new personaj();
        c->x = x;
        c->y = y;
        c->name = name;
        c->m_sound = m_sound;  // 8B
        c->m_texture = m_texture;  // shallow clone
        return c;
    }

private:
    shared_ptr<texture> m_texture;
    shared_ptr<sound> m_sound;

    void load_sound()
    {
        cout << "loading sound...";
        fflush(stdout);
        this_thread::sleep_for(1s);
        m_sound = make_shared<sound>();
        cout << "OK\n";
    }

    void load_texture()
    {
        cout << "loading texture...";
        fflush(stdout);
        this_thread::sleep_for(2s);
        m_texture = make_shared<texture>();
        cout << "OK\n";
    }
};


string operator+(const string &s, int i)
{
    stringstream ss;
    ss << s << i;
    return ss.str();
}


int main()
{
    personaj sample{-1, -1, "sample"};  // prototip

    vector<node2d*> nodes;

    string name{ "personaj" };
    for (int i = 0; i < 100; i++) {
        node2d *c = sample.clone();
        c->setX(i * 2);
        c->setY(i + 1);
        c->setName("personaj " + i);
        nodes.push_back(c);

        // varianta 2 (C++):
        auto c = new personaj(sample);
        c->setX(i * 10);
        c->setY(i + 5);
        c->setName(name + i);
        nodes.push_back(c);
    }

    for (auto n : nodes)
        cout << *n << endl;

    for (auto n : nodes)
        delete n;
}