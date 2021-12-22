#include <iostream>
#include "sales.h"

using namespace std;

int main()
{
    using namespace SALES;
    SALES::Sales s;
    double ar[4] = {200.0,100.0,300.0,400.0};
    setSales(s, ar, 4);
    showSales(s);    
    return 0;
}