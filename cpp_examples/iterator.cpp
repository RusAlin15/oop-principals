#include <iostream>

using namespace std;


template<typename T>
class stack
{
public:
    stack(size_t cap) : m_capacity{cap}
    {
        buf = new T[m_capacity];
    }

    stack &push(const T &obj)
    {
        if (m_size == m_capacity)
            increase_capacity();

        buf[m_size++] = obj;
        return *this;
    }

    T pop()
    {
        if (m_size == 0)
            throw "Underflow error"s;
        return buf[--m_size];
    }

    size_t capacity() const { return m_capacity; }
    size_t size() const { return m_size; }

    class iterator;

    iterator begin()
    {
        return iterator{0, *this};
    }

    iterator end()
    {
        return iterator{m_size, *this};
    }

    T operator[](size_t pos)
    {
        if (pos >= m_size)
            throw "Overflow error"s;
        return buf[pos];
    }

private:
    T *buf{};
    size_t m_capacity{};
    size_t m_size{};

    void increase_capacity()
    {
        T *old = buf;
        m_capacity += 10;
        buf = new T[m_capacity];

        for (size_t i = 0; i < m_size; i++)
            buf[i] = old[i];  // copy ctor
        delete[] old;
    }

};


template<typename T>
class stack<T>::iterator
{
public:
    iterator(size_t pos, stack &s) : pos{pos}, s{s} {}

    bool operator!=(const iterator &o) { return pos != o.pos && this != &o; }
    bool operator==(const iterator &o) { return pos == o.pos && this == &o; }  // TODO

    iterator &operator++()  // prefix ++
    {
        pos++;
        return *this;
    }

    iterator operator++(int)  // postfix ++
    {
        iterator old = *this; // copie a ob curent
        pos++;
        return old;
    }

    T operator*()
    {
        return s[pos];
    }

private:
    size_t pos;
    stack &s;  // 8B (referinta)
};


int main()
{
    stack<int> s{3};
    s.push(1).push(2).push(3).push(4);
    cout << s.capacity() << endl;
    cout << s.pop() << endl;

    for (int e : s)
        cout << e << " ";
    cout << endl;

    // old school:
    //for (stack<int>::iterator it = s.begin(); it != s.end(); ++it)
    //    cout << *it << " ";
    //cout << endl;
}