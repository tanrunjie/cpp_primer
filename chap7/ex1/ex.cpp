#include<iostream>

using namespace std;

float Avg(float a, float b)
{
    return 2.0*a*b/(a+b);
}

int main()
{
    float a,b;
    while(1)
    {
        cin >> a >> b;
        if(a==0 || b==0)
        {
            break;
        }
        cout << Avg(a,b) << endl;
    }
    return 0;
}