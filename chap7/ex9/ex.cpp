#include <iostream>
using namespace std;

double add(double x, double y)
{
    return x + y;
}
double minuss(double x, double y)
{
    return x - y;
}
double mul(double x, double y)
{
    return x * y;
}
double calculate(double x, double y, double (*pf)(double, double))
{
    return (*pf)(x, y);
}
int main()
{
    double x, y;
    double (*pf[])(double,double) = {add, minuss, mul};
    while (cin >> x >> y)
    {
        for(int i=0;i<3;i++)
        {
        cout << calculate(x, y, pf[i]) << endl;
        }
    }
    return 0;
}