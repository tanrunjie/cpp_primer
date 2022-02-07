#include <iostream>
#include <cmath>
#include <cstring>
#include "exc_mean.h"

using namespace std;

class demo
{
private:
    char word[40];

public:
    demo(const char *str)
    {
        strcpy(word, str);
        cout << "demo " << word << " created\n";
    }
    ~demo()
    {
        cout << "demo " << word << " destroyed\n";
    }
    void show() const
    {
        cout << "demo " << word << " lives!\n";
    }
};

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
double means(double a, double b) throw(bad_hmean, bad_gmean)
{
    double am, hm, gm;
    demo d2("found in means()");
    am = (a + b) / 2.0;
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch (bad_hmean &bg)
    {
        bg.mesg();
        cout << "Caught in means()\n";
        throw;
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}
int main()
{
    double x, y, z;
    demo d1("found in main()");
    cout << "Enter two numbers:";
    while (cin >> x >> y)
    {
        try
        {
            z = means(x, y);
            cout << "The mean of " << x << " and " << y << " is " << z << endl;
            cout << "Enter next pair: ";
        }
        catch (bad_hmean &bg)
        {
            bg.mesg();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean &hg)
        {
            cout << hg.mesg();
            cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    d1.show();
    cout << "Bye!" << endl;
    return 0;
}