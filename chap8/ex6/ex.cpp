#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maxn(T t[], int n)
{
    T max = t[0];
    for (int i = 1; i < n; i++)
        if (t[i] > max)
            max = t[i];
    return max;
}
template <>
char *maxn(char *p[], int n)
{
    int max = strlen(p[0]);
    char *maxp = p[0];
    for (int i = 1; i < n; i++)
        if (strlen(p[i]) > max)
        {
            max = strlen(p[i]);
            maxp = p[i];
        }
    return maxp;
}

int main()
{
    int i[6] = {3, 1, 2, 7, 5, 6};
    double d[4] = {4.4, 1.1, 6.6, 2.2};
    char *p[5] = {(char*)"I love you", (char*)"you love me", (char*)"I am ryan",
                  (char*)"hello world", (char*)"doing it!"};
    cout << maxn(i, 6) << endl;
    cout << maxn(d, 4) << endl;
    cout << maxn(p, 5) << endl;
    return 0;
}