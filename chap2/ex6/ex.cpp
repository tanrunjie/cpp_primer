#include <iostream>
using namespace std;

int main()
{
    float dist, gas;
    cout <<" input distance(km) and gas(liter):";
    cin >> dist >> gas;
    cout << "every 100 km burn " << gas*(dist/100.0) <<" liters gas" <<endl;
    
    float dist_a = dist/62.14;
    float gas_a = gas/3.875;
    cout << "every galon run " << gas_a *(dist_a) << " dis_a" << endl;
    return 0;
}