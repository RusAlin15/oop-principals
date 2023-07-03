#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

class memento
{
public:
    memento(const vector<string> &lines) : lines{lines} {}

    vector<string> getState() const { return lines; }

private:
    vector<string> lines;
};


// originator
class notepad
{
public:
    notepad(const string &name) : name{name} {}

    notepad &add(const string &line)
    {
        lines.push_back(line);
        return *this;
    }

    memento export_state() const { return memento{lines}; }

    void restore_state(const memento &m) { lines = m.getState(); }  // TODO

    friend ostream &operator<<(ostream &out, const notepad &n)
    {
        for (auto l : n.lines)
            out << l << endl;
        return out;
    }

private:
    vector<string> lines;
    string name;
};


class undo_manager // caretaker
{
public:
    void push_state(const memento &m) { history.push(m); }

    memento pop_state()
    {
        auto mem = history.top();
        history.pop();
        return mem;
    }

private:
    stack<memento> history;
};


int main()
{
    undo_manager manager;

    notepad doc{"doc.txt"};
    doc.add("Ana are mere").add("Salut. Ce mai faci?");
    cout << doc << endl;
    manager.push_state(doc.export_state());  // on event...

    doc.add("Inca o linie");
    cout << doc << endl;

    cout << "UNDO:\n";
    doc.restore_state(manager.pop_state());
    cout << doc << endl;
}