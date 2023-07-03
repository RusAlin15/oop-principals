#include <iostream>
#include <string>
#include <vector>

using namespace std;

class employee;
class manager;
class developer;
class accountant;


class employee_operation
{
public:
    virtual void visit(employee &e) = 0;
    virtual void visit(manager &e) = 0;
    virtual void visit(developer &e) = 0;
    virtual void visit(accountant &e) = 0;
};


class employee
{
public:
    employee(const string &name, double sal) : name{name}, salary{sal} {}

    void increaseSalary(double delta) { salary += delta; }

    string getName() const { return name; }
    double getSalary() const { return salary; }

    virtual void operate(employee_operation &op) { op.visit(*this); }

protected:
    string name;
    double salary;
};


class manager : public employee
{
public:
    manager(const string &name, double sal, double dividende=0) : employee(name, sal), dividende{dividende} {}

    virtual void operate(employee_operation &op) { op.visit(*this); }

    double getDividende() const { return dividende; }

private:
    double dividende;
};


class developer : public employee
{
public:
    developer(const string &name, double sal) : employee(name, sal) {}

    virtual void operate(employee_operation &op) { op.visit(*this); }
};


class accountant : public employee
{
public:
    accountant(const string &name, double sal) : employee(name, sal) {}

    virtual void operate(employee_operation &op) { op.visit(*this); }
};


//////////////////////////////////////////////////////////////////////

class tax_collector : public employee_operation
{
public:
    void visit(employee &e) { tax += e.getSalary() * 0.16; }

    void visit(manager &e) { tax += e.getSalary() * 0.16 + e.getDividende() * 0.1; }

    void visit(developer &e) { cout << "special case\n"; }

    void visit(accountant &e) { tax += e.getSalary() * 0.12; }

    double getTax() const { return tax; }

private:
    double tax;
};


class code_writing : public employee_operation
{
public:
    void visit(employee &e) { }

    void visit(manager &e) { }

    void visit(developer &e) { cout << e.getName() << " writes some awesome code\n"; }

    void visit(accountant &e) { }
};


int main()
{
    vector<employee*> employees {
        new manager{"Marius", 1000, 200},
        new developer{"John", 1000},
        new developer{"Ioana", 1000},
        new accountant{"Simona", 1000}
    };

    tax_collector c;
    code_writing cw;
    for (auto e : employees) {
        e->operate(c);
        e->operate(cw);
    }

    cout << "Taxa pt ANAF = " << c.getTax() << endl;

    for (auto e : employees)
        delete e;
}