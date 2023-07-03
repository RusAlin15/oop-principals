#include <iostream>


using namespace std;


class sample
{
public:
    class builder
    {
    public:
        friend class sample;

        friend sample config1(int i1, int i2, int i3);

        friend sample config2(int i4, int i5);

    private:
        builder &i1(int i) { m_i1 = i; return *this; }
        builder &i2(int i) { m_i2 = i; return *this; }
        builder &i3(int i) { m_i3 = i; return *this; }
        builder &i4(int i) { m_i4 = i; return *this; }
        builder &i5(int i) { m_i5 = i; return *this; }

        sample build() { return sample(*this); }

    // private:
        int m_i1{};
        int m_i2{};
        int m_i3{};
        int m_i4{};
        int m_i5{};
    };

    friend ostream &operator<<(ostream &o, const sample &s)
    {
        o << s.i1 << ", " << s.i2 << ", " << s.i3 << ", " << s.i4 << ", " << s.i5;
        return o;
    }

private:
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;

    sample(builder &b) :
        i1{b.m_i1}, i2{b.m_i2}, i3{b.m_i3}, i4{b.m_i4}, i5{b.m_i5}
    {}
};

sample config1(int i1, int i2, int i3)
{
    return sample::builder().i1(i1).i2(i2).i3(i3).build();
}

sample config2(int i4, int i5)
{
    return sample::builder().i4(i4).i5(i5).build();
}


int main()
{
    sample s1 = config1(10, 20, 30);  // sample::builder().i1(10).i3(20).build();
    sample s2 = config2(40, 50);  // sample::builder().i1(100).i4(20).i5(40).build();

    cout << s1 << endl;
    cout << s2 << endl;
}