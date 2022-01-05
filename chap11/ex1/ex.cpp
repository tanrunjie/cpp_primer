#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout <<" Enter target distance(q to quit)";
    
    ofstream outFile;
    outFile.open("file.txt");
    if(!outFile.is_open())
    {
        cerr << "Failed open file.txt\n";
        exit(0);
    }
    while(cin>>target)
    {
        cout <<"Enter step length:";
        if(!(cin>>dstep))
            break;

        outFile << "Target Distance: " << target <<", Step Size: " << dstep << endl;
        outFile << steps <<": (x,y) = (" << result.xval() << ", " << result.yval() <<")\n";
        while(result.magval() < target)
        {

            direction = rand()%360;
            step.set(dstep, direction, 'p');
            result = result + step;
            steps++;
  
            outFile << steps <<": (x,y) = (" << result.xval() << ", " << result.yval() <<")\n";

        }
        outFile <<"After " << steps << " steps, the subject "
        "has the following location:" << endl;
        outFile << result << endl;
        result.polar_mode();
        outFile <<" or\n" << result << endl;
        outFile << "Average outward distance per step = "
        << result.magval()/steps << endl;
        steps = 0;
        result.set(0.0, 0.0);
        cout <<"Enter target distance(q to quit):";
    }
    outFile.close();
    cout <<"Bye!" << endl;

    return 0;
}
