#include <iostream>

using namespace std;

int recurs(int n)
{
    if(n==0)
        return 1;
    else
        return n*recurs(n-1);
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout << recurs(n) <<endl;
    }
    return 0;
}