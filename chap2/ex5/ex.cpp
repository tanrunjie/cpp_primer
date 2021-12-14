#include <iostream>
using namespace std;

int main()
{
    float dist, gas;
    cout <<" input distance(km) and gas(liter):";
    cin >> dist >> gas;
    cout << "every 100 km burn " << gas*(dist/100.0) <<" liters gas" <<endl;
    return 0;
}