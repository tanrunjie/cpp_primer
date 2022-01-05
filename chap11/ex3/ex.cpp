#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    cout << " Enter N:";
    int time = 0;
    cin >> time;
    vector<unsigned long> vec;
    unsigned long sum;
    cout << " Enter target distance(q to quit)";
    while (cin >> target)
    {
        cout << "Enter step length:";
        if (!(cin >> dstep))
            break;
        sum = 0;
        for (int i = 0; i < time; i++)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.set(dstep, direction, 'p');
                result = result + step;
                steps++;
            }
            cout << "After " << steps << " steps, the subject "
                                         "has the following location:"
                 << endl;
            vec.push_back(steps);
            sum += steps;
            cout << result << endl;
            result.polar_mode();
            cout << " or\n"
                 << result << endl;
            cout << "Average outward distance per step = "
                 << result.magval() / steps << endl;
            steps = 0;
            result.set(0.0, 0.0);
        }
        sort(vec.begin(),vec.end());
        cout <<"Most steps:" << vec[vec.size()-1] << endl;
        cout <<"Least steps:" << vec[0] << endl;
        cout <<"Avg steps:" << sum*1.0 / (vec.size()*1.0) << endl;
        

        cout << "Enter target distance(q to quit):";
    }
    cout << "Bye!" << endl;

    return 0;
}
