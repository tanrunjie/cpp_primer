#include <iostream>
#include "Winec.h"

using namespace std;
int main()
{
    cout <<"Enter name of wine:";
    char lab[50];
    cin.getline(lab, 50);
    cout <<"Enter number of years:";
    int yrs;
    cin >> yrs;
    
    Wine holding(lab, yrs);
    holding.show();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};

    Wine more("Gushing Grape Red", YRS, y,b);
    more.show();

    cout <<"Total bottles for " << more.Label()
    <<": " << more.sum() << endl;
    cout <<"Bye" << endl;
    
    return 0;
}