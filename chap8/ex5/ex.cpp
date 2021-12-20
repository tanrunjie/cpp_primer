#include <iostream>
using namespace std;

template <typename T>
T max5(T t[5])
{
    T max = t[0];
    for (int i = 1; i < 5; i++)
    {
        if (t[i] > max)
            max = t[i];
    }
    return max;
}
int main()
{
    int i[5] = {2, 8, 4, 6, 10};
    double d[5] = {1.1, 4.4, 2.2, 6.6, 7.7};
    cout << max5(i) << endl;
    cout << max5(d) << endl;
    return 0;
}