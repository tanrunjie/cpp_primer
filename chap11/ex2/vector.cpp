#include <cmath>
#include "vector.h"

using namespace std;

namespace VECTOR
{
    const double Rad_to_deg = 57.2957795130823;

    double Vector::magval() const
    {
        return sqrt(x * x + y * y);
    }

    double Vector::angval() const
    {
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y, x);
    }

    Vector::Vector()
    {
        x = y = 0.0;
        mode = 'r';
    }
    Vector::Vector(double n1, double n2, char form)
    {
        mode = form;
        if (form == 'r')
        {
            x = n1;
            y = n2;
        }
        else if (form == 'p')
        {
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            x = mag * cos(ang);
            y = mag * sin(ang);
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector()--";
            cout << "Vector set to 0\n";
            x = y = 0.0;
            mode = 'r';
        }
    }

    void Vector::set(double n1, double n2, char form)
    {
        mode = form;
        if (form == 'r')
        {
            x = n1;
            y = n2;
        }
        else if (form == 'p')
        {
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            x = mag * cos(ang);
            y = mag * sin(ang);
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector()--";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = 'r';
        }
    }
    Vector::~Vector() {}

    void Vector::polar_mode()
    {
        mode = 'p';
    }
    void Vector::rect_mode()
    {
        mode = 'r';
    }

    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x + b.x, y + b.y);
    }
    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x - b.x, y - b.y);
    }
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }
    std::ostream &operator<<(std::ostream &os, const Vector &v)
    {
        if (v.mode == 'r')
            os << " (x,y) = (" << v.x << ". " << v.y << ")";
        else if (v.mode == 'p')
        {
            os << " (m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
        }
        else
            os << "Vector objet mode is invalid";
        return os;
    }
}