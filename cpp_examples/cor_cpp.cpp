#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class email
{
public:
    email(const string &from, const string &to, const string &subj, const string &msg) :
        from(from), to(to), subj(subj), message(msg) {}

    string getFrom() const { return from; }
    string getTo() const { return to; }
    string getSubj() const { return subj; }
    string getMessage() const { return message; }
private:
    string from, to;
    string subj;
    string message;
};

ostream &operator<<(ostream &o, const email &e)
{
    o << e.getFrom() << ": " << e.getSubj();
    return o;
}


class outlook;


class filter
{
public:
    filter(outlook &o) : client{o} {}

    virtual void handle(email &e);

    void add(filter *f) { filters.push_back(f); }

    virtual bool do_filter(email &e) { return false; }

protected:
    outlook &client;
    vector<filter*> filters;  // TODO
};

class default_filter : public filter
{
public:
    default_filter(outlook &o) : filter{o} {}

    bool do_filter(email &e) override;
};


class from_filter : public filter
{
public:
    from_filter(const string &from, const string &fn, bool cp, outlook &o) :
        filter{o}, from{from}, folder{fn}, continue_processing{cp}
    {}

    bool do_filter(email &e) override;

private:
    string from;
    string folder;
    bool continue_processing;
};


class outlook
{
public:
    outlook()
    {
        root = new filter(*this);
        folders["spam"] = {};
        folders["inbox"] = {};
        folders["organization"] = {};
    }

    ~outlook() { delete root; }

    outlook(const outlook &o) = delete;

    vector<email> &getFolder(const string &name) { return folders[name]; }

    void show_folders() const
    {
        for (auto f : folders) {
            cout << "===";
            cout << f.first << ":\n";
            for (auto &e : f.second)
                cout << e << endl;
        }
    }

    void email_received(email &e) { root->handle(e); }
    void add_filter(filter *f) { root->add(f); }

private:
    map<string, vector<email>> folders;
    filter *root;
};


bool default_filter::do_filter(email &e)
{
    client.getFolder("inbox").push_back(e);
    return true;
}

bool from_filter::do_filter(email &e)
{
    if (e.getFrom() == from) {
        client.getFolder(folder).push_back(e);
        return !continue_processing;
    }
    return false;
}


void filter::handle(email &e)
{
    bool finalized = false;
    for (auto f : filters) {
        finalized = f->do_filter(e);
        if (finalized)
            break;
    }

    // fallback
    //if (!processed)
    //    client.getFolder("inbox").push_back(e);
}


int main()
{
    outlook o;
    from_filter ion{"ion@gmail.com", "organization", false, o};
    from_filter marian{"marian@gmail.com", "organization", false, o};
    from_filter gates{"gates@microsoft.com", "spam", false, o};
    default_filter def{o};

    o.add_filter(&ion);
    o.add_filter(&marian);
    o.add_filter(&gates);
    o.add_filter(&def);

    email e1{"ion@gmail.com", "me@me.com", "Subj", "My Message"};
    email e2{"marian@gmail.com", "me@me.com", "Subj", "My Message"};
    email e3{"gates@microsoft.com", "me@me.com", "Subj", "My Message"};
    email e4{"ioana@gmail.com", "me@me.com", "Subj", "My Message"};

    o.email_received(e1);
    o.email_received(e2);
    o.email_received(e3);
    o.email_received(e4);

    o.show_folders();
}