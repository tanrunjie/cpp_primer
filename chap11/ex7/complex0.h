#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>
class complex
{
    protected:
        double real;
        double imag;
    public:
        complex();
        complex(double,double);
        complex operator+(const complex c);
        complex operator-(const complex c);
        complex operator*(const complex c);
        friend complex operator*(double n, const complex c);

        friend std::ostream & operator<<(std::ostream &os, const complex c);
        friend std::istream & operator>>(std::istream &is, complex& c);
        friend complex operator~(const complex c);

        ~complex();

};

#endif