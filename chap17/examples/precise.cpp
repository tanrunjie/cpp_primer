#include <iostream>
using namespace std;

int main()
{
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;
    cout << "Furry Friends is $" << price1 << endl;
    cout << "Fiery Friends is $" << price2 << endl;

    cout.precision(2); // 两位有效数字
    cout << "Furry Friends is $" << price1 << endl;
    cout << "Fiery Friends is $" << price2 << endl;
    return 0;
}