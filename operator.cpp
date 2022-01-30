// 15 april 2018
// operator overloading
#include <iostream>
#include <conio.h>

using namespace std;

class Cmplex
{
    float m_real, m_imag;

public:
    Cmplex(float r = 0.f, float i = 0.f)
    {
        m_real = r; m_imag = i;
    }

    Cmplex(const Cmplex &other)
    {
        m_real = other.m_real;
        m_imag = other.m_imag;
    }

    float real(){ return m_real;}
    float imag(){ return m_imag;}
    void setReal(float r) {m_real = r;}
    void setImag(float i) {m_imag = i;}

    Cmplex operator +(const Cmplex &c1)
    {
        Cmplex ret;
        ret.m_real = m_real + c1.m_real;
        ret.m_imag = m_imag + c1.m_imag;
        return ret;
    }
};

int main()
{
    Cmplex start;
    Cmplex mid(3.0, 2.5);
    Cmplex last(4.5, 3.0);

    Cmplex ret = mid + last;

    cout << "start: " << start.real() << " + " << start.imag() << "i" << endl;
    cout << "addition of mid + last: " << ret.real() << " + " <<ret.imag() << "i" << endl;

    getch();
    return 0;
}
