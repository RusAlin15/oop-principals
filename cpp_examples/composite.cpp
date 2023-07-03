#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

class File;
class TextFile;
class CppFile;
class Folder;


// Visitor
class file_operation
{
public:
    virtual void process(File &f) = 0;
    virtual void process(TextFile &f) = 0;
    virtual void process(CppFile &f) = 0;
    virtual void process(Folder &f) = 0;
};


class File
{
public:
    File(const string &fn, const string &ext) : name{fn}, ext{ext} {}
    string getName() const { return name; }
    string getExt() const { return ext; }

    virtual void open() const { cout << "Opened " << name << "." << ext << endl; }
    virtual string cat() const = 0;

    virtual void operate(file_operation &op) = 0;  // nu exista *this (cls abstracta)

protected:
    string name;
    string ext;
};


class TextFile : public File
{
public:
    TextFile(const string &fn, const string &text) : File(fn, "txt"), content{text} {}
    string cat() const override { return content; }

    virtual void operate(file_operation &op) { op.process(*this); }

protected:
    string content;
};


class CppFile : public TextFile
{
public:
    CppFile(const string &fn, const string &content) : TextFile(fn, content)
    {
        ext = "cpp";
    }

    void compile() { cout << "Compiling " << name << ".cpp\n"; }

    virtual void operate(file_operation &op) { op.process(*this); }
};


class Folder : public File
{
public:
    Folder(const string &name) : File(name, "") {}

    void open() const override { cout << "Opened " << name << endl; }

    string cat() const override
    {
        stringstream ss;
        ss << name << ":\n";
        for (auto child : children)
            ss << child.get().getName() << ": " << child.get().cat() << endl;

        return ss.str();
    }

    Folder &add(File &f)
    {
        children.emplace_back(ref(f));
        return *this;
    }

    void rm(const string &name)
    {
        children.erase(remove_if(children.begin(), children.end(), [name](auto f){ return f.get().getName() == name; }));
    }

    virtual void operate(file_operation &op)
    {
        op.process(*this);
        for (auto e : children)
            op.process(e.get());
    }

protected:
    vector<reference_wrapper<File>> children;
};


////////////////////////////////////////////////////////////////////////////////
class file_size : public file_operation
{
public:
    void process(File &f) override
    {
        // cout << "Interesting\n";
        f.operate(*this);  // routing: du-te in TextFile.operate(file_size&) => du-te inapoi in file_size.process(TextFile&)
    }

    void process(TextFile &f) override
    {
        auto size = f.cat().size();
        cout << "Size of " << f.getName() << "." << f.getExt() << ": " << size << endl;
        total_size += size;
    }

    void process(CppFile &f) override
    {
        auto size = f.cat().size();
        cout << "Size of " << f.getName() << "." << f.getExt() << ": " << size << endl;
        total_size += size;
    }

    void process(Folder &f) override
    {
        auto size = 4096;
        cout << "Size of " << f.getName() << ": " << size << endl;
        total_size += size;
    }

    auto getSize() const { return total_size; }

private:
    size_t total_size{};
};


class compilation : public file_operation
{
public:

    void process(File &f) override
    {
        f.operate(*this);
    }

    void process(TextFile &f) override
    {
    }

    void process(CppFile &f) override
    {
        f.compile();
    }

    void process(Folder &f) override
    {
    }
};


int main()
{
    TextFile f11{"f11", "Ana are mere. Content11"};
    TextFile f12{"f12", "Ana are mere. Content12"};
    TextFile f13{"f13", "Ana are mere. Content13"};
    TextFile f14{"f14", "Ana are mere. Content14"};
    CppFile f15{"f15", "#include ...."};

    Folder subfolder{"Subfolder"};
    TextFile f21{"f21", "Ana are mere. Content21"};
    TextFile f22{"f22", "Ana are mere. Content22"};
    TextFile f23{"f23", "Ana are mere. Content23"};

    subfolder.add(f21).add(f22).add(f23);
    Folder root{"root"};
    root.add(subfolder).add(f11).add(f12).add(f13).add(f14).add(f15);

    cout << root.cat() << endl;

    file_size fs;
    root.operate(fs);
    cout << "Total size: " << fs.getSize() << endl;

    compilation c;
    root.operate(c);;
}