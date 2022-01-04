#include "sales.hpp"

int main()
{
    SALES::Sales s;

    double ar[4] = {200.0,100.0,300.0,400.0};
    s.setSales( ar, 4);
    s.showSales();    
    return 0;
}