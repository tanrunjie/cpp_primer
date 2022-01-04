#ifndef _SALES_H
#define _SALES_H

#include <iostream>
using namespace std;

namespace SALES
{
    const int QUARTERS = 4;
    class Sales
    {
    private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;

    public:
        void setSales(const double ar[], int n)
        {
            for (int i = 0; i < QUARTERS; i++)
                if (i < n)
                    sales[i] = ar[i];
                else
                    sales[i] = 0;

            double sum = 0.0;
            double tmax = sales[0];
            double tmin = sales[0];
            for (int i = 0; i < SALES::QUARTERS; i++)
            {
                sum += sales[i];
                if (sales[i] > max)
                    tmax = sales[i];
                if (sales[i] < min)
                    tmin = sales[i];
            }
            average = sum / SALES::QUARTERS;
            max = tmax;
            min = tmin;
        }

        void setSales(Sales &s);

        void showSales() const
        {
            cout << "sales:";
            for (int i = 0; i < SALES::QUARTERS; i++)
                cout << sales[i] << " ";
            cout << endl;

            cout << "average:" << average << endl;
            cout << "max:" << max << endl;
            cout << "min:" << min << endl;
        }
    };

}

#endif