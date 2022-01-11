#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}
using namespace std;

int main()
{
    srand(time(0));
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue:";
    int qs;
    cin >> qs;
    Queue line1(qs);
    Queue line2(qs);
    cout << "Enter the number of simulation hours:";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    int perhour;
    for (perhour = 1; perhour < 1000; perhour++)
    {

        cout << "Enter the average number of customers per hour:" << perhour << endl;
        double min_per_cust;
        min_per_cust = MIN_PER_HR / perhour;

        Item temp;
        long turnaways = 0;
        long customers = 0;
        long served = 0;
        long sum_line1 = 0;
        long sum_line2 = 0;

        int wait_time1 = 0;
        int wait_time2 = 0;

        long line_wait1 = 0;
        long line_wait2 = 0;


        for (int cycle = 0; cycle < cyclelimit; cycle++) // cycle = minute
        {
            if (newcustomer(min_per_cust))
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    if(line1.queuecount()<= line2.queuecount())
                        line1.enqueue(temp);
                    else
                        line2.enqueue(temp);
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);
                wait_time1 = temp.ptime();
                line_wait1 += cycle - temp.when();
                served++;
            }
            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp);
                wait_time2 = temp.ptime();
                line_wait2 += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            if (wait_time2 > 0)
                wait_time2--;
            sum_line1 += line1.queuecount();
            sum_line2 += line2.queuecount();

        }

        if (customers > 0)
        {
            int line_wait = line_wait1 + line_wait2;
            cout << "customers accepted:" << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "      tuurnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout.setf(ios_base::showpoint);
            cout << (double)sum_line1 / cyclelimit << endl;
            cout << (double)sum_line2 / cyclelimit << endl;

            // cout << "line_wait:" << line_wait<<endl;
            // cout << "served:" << served<<endl;

            cout << " average wait time: " << (double)line_wait / served << " minutes\n";
            if((double)line_wait / served >1.0)
                break;
        }
        else
            cout << "No customers!\n";
    }
    cout <<"avg customer per hour:" << perhour << " will need wait more than one minute" << endl;
    cout << "Done!\n";
    return 0;
}
