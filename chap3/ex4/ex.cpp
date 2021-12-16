#include <iostream>
using namespace std;

int main()
{
    long sec;
    cout <<"Enter the number of seconds:";
    cin >> sec;
    const int hourPerDay = 24;
    const int minPerHour = 60;
    const int secPerMin = 60;

    int days = sec/(hourPerDay*minPerHour*secPerMin);
    int mins = ((sec - days*(hourPerDay*minPerHour*secPerMin))/(secPerMin))% minPerHour;
    int secs = (sec-days*((hourPerDay*minPerHour*secPerMin)) - mins*secPerMin) % secPerMin;
    cout <<sec <<" seconds = " << days \
    <<" days, " << mins << " minutes, " << secs <<" seconds" << endl;
    return 0;
}