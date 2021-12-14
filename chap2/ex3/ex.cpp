#include <iostream>

using namespace std;

int main()
{
    int degree, minute,second;
    cout <<"Enter a latitude in degrees, minutes, and seconds:" <<endl;
    cout <<"First, enter the degrees:";
    cin >> degree;
    cout <<"Next, enter the minutes of arc:";
    cin >> minute;
    cout <<"Finally, enter the seconds of arc:";
    cin >> second;
    float res = degree + (second/60.0 +minute)/60.0;
    cout <<degree <<" degrees, " << minute <<" minutes, " << second \ 
    << " seconds =" << res <<" degrees"<<endl;
    return 0;
}