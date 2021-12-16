#include <iostream>
int main()
{
    using namespace std;

    float x;
    float sum = 0;
    while(cin>>x && x!=0)
    {
        sum+=x;
        cout <<"So far:" << sum << endl;
    }
    return 0;
}