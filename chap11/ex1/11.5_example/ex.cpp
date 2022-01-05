#include "mytime1.h"
#include <iostream>

using namespace std;
int main()
{
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;

    cout << "total time = ";
    total.Show();
    cout << endl;


    Time morefixing(3, 28);
    cout <<"more fixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    cout <<"morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    return 0;
}