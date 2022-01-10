#include <iostream>
#include "stock2.h"

using namespace std;

const int STKS = 4;
int main()
{
    Stock stocks[STKS]= {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);

    cout <<"Stock holdings:\n";
    int st;
    for(st=0; st<STKS; st++)
    {
        cout << stocks[st];
    }

    Stock top = stocks[0];
    for(st=0; st<STKS; st++)
    {
        top = top.topval(stocks[st]);
    }
    cout <<"\nMost valuable holding:\n";
    cout << top;

    return 0;
}