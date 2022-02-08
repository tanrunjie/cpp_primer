#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b) throw(bad_hmean)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) throw(bad_gmean)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return sqrt(a * b);
}

int main()
{
    double x, y, z;
    cout << "Enter two numbers:";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
        }
        catch (bad_gmean &hg)
        {
            cout << endl;

            cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
        catch (bad_hmean &bg)
        {
            cout << bg.what();
            cout << "Try again.\n";
            continue;
        }
    }
    cout << "Bye!" << endl;
    return 0;
}