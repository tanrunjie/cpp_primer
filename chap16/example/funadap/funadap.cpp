// 16.14
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

const int LIM = 5;
void Show(double v)
{
    cout.width(6);
    cout << v << ' ';
}

int main()
{
    double arr1[LIM] = {36, 39, 42, 45, 48};
    double arr2[LIM] = {25, 27, 29, 31, 33};
    vector<double> gr8(arr1, arr1+LIM);
    vector<double> m8(arr2, arr2+LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout <<"gr8: \t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout << endl;
    cout <<"m8: \t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;

    vector<double> sum(LIM);
    // transform usage
    transform(gr8.begin(),gr8.end(),m8.begin(), sum.begin(),plus<double>());
    cout <<"sum: \t";
    for_each(sum.begin(),sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);
    transform(gr8.begin(),gr8.end(),prod.begin(),bind1st(multiplies<double>(),2.5));
    cout <<"prod: \t";
    for_each(prod.begin(), prod.end(), Show);
    cout << endl;
    return 0;
}