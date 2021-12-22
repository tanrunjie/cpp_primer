#include "sales.h"

using namespace SALES;
using namespace std;
void SALES::setSales(Sales &s, const double ar[], int n)
{
    for (int i = 0; i < SALES::QUARTERS; i++)
        if (i < n)
            s.sales[i] = ar[i];
        else
            s.sales[i] = 0;

    double sum = 0.0;
    double max = s.sales[0];
    double min = s.sales[0];
    for (int i = 0; i < SALES::QUARTERS; i++)
    {
        sum += s.sales[i];
        if(s.sales[i] > max)
            max = s.sales[i];
        if(s.sales[i] < min)
            min = s.sales[i];
    }
    s.average = sum/SALES::QUARTERS;
    s.max = max;
    s.min = min;
}

void SALES::setSales(Sales &s)
{

}

void SALES::showSales(const Sales &s)
{
    cout << "sales:";
    for (int i = 0; i < SALES::QUARTERS; i++)
        cout << s.sales[i] << " ";
    cout << endl;

    cout << "average:" << s.average << endl;
    cout << "max:" << s.max << endl;
    cout << "min:" << s.min << endl;
}