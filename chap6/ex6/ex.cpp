#include <iostream>
#include <string>
using namespace std;
int main()
{
    struct donator{
        string name;
        double money;
    };
    donator *pd = new donator[5];
    cout <<"Input five donator's info.\n";
    for(int i=0; i<5; i++)
    {
        cin >> pd[i].name;
        cin >> pd[i].money;
    }
    for(int i=0; i<5; i++)
    {
        if(pd[i].money > 10000)
        {
            cout <<"Grand Patrons:" << pd[i].name \
            <<" with money:" <<pd[i].money << endl;
        }
        else
        {
            cout <<"Patrons:" <<pd[i].name \
            <<" with money:" << pd[i].money << endl;
        }
    }
    return 0;
}