#include "complex0.h"

using namespace std;

complex::complex()
{
    real = imag = 0.0;
}

complex::complex(double r, double i)
{
    real = r;
    imag = i;
}

ostream& operator<<(ostream& os, const complex c)
{
    os<<"(" <<c.real <<"," << c.imag <<"j)"<<endl;
    return os;
}

istream& operator>>(istream& is, complex& c)
{
    cout <<"input real part:";
    is>>c.real;
    cout <<"input imag part:";
    is>>c.imag;
    return is;
}

complex operator~(const complex c)
{
    complex con;
    con.real = c.real;
    con.imag = -c.imag;
    return con;
}

complex complex::operator+(const complex c)
{
    complex sum;
    sum.real = real + c.real;
    sum.imag = imag + c.imag;
    return sum;
}

complex complex::operator-(const complex c)
{
    complex diff;
    diff.real = real - c.real;
    diff.imag = imag - c.imag;
    return diff;
}

complex complex::operator*(const complex c)
{
    complex res;
    res.real = real*c.real - imag*c.imag;
    res.imag =   imag * c.real + real*c.imag; 
    return res;
}

complex operator*(double n, const complex c)
{
    complex res;
    res.real = c.real * n;
    res.imag = c.imag * n;
    return res;
}

complex::~complex(){}