#include <iostream>
using namespace std;

int main()
{
    cout  << "12345678901234567890" << endl;
    char ch = 'K';
    int t = 273;

    cout << ch << endl;
    cout << t << endl;
    cout << -t << endl;

    double f1 = 1.200;
    cout <<f1  << endl;
    cout <<(f1 + 1.0/9.0) << endl;

    double f2 = 1.67E2;
    cout << f2 << endl;
    f2 += 1.0/9.0;
    cout << f2 << endl;
    cout << (f2 *1.0e4) << endl;


    double f3 = 2.3e-4;
    cout << f3<<endl;
    cout << f3/10 << endl;

    return 0;
}