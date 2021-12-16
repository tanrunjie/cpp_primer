#include <iostream>
int main()
{
    using namespace std;

    int x, y;
    cin >> x >> y;
    int sum = 0;
    for (int i = x; i <= y; i++)
    {
        sum += i;
    }
    cout << sum << endl;

    return 0;
}