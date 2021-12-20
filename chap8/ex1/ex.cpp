#include <iostream>
using namespace std;
void print(const char *str, int times=3)
{
    if (times)
    {
        cout << str;
        print(str, times-1);
    }
}

int main()
{
    const char *str = "hello";
    print(str, 5);
    cout << endl;
    print(str);
    return 0;
}