#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
namespace VECTOR
{
    class Vector
    {
        private:
            double x;
            double y;
           
            char mode; // 'r' rectangular, 'p' polar
            

        public:
            Vector();
            Vector(double n1, double n2, char form='r');
            void set(double n1, double n2, char form='r');
            ~Vector();
            double xval() const {return x;}
            double yval() const {return y;}
            double magval() const ;
            double angval() const ;
            void polar_mode();
            void rect_mode();

            Vector operator+ (const Vector & b) const;
            Vector operator- (const Vector & b) const;
            Vector operator- () const;
            Vector operator* (double n) const;

            friend Vector operator*(double n, const Vector & a);
            friend std::ostream & operator<<(std::ostream & os, const Vector & v);

    };
}

#endif