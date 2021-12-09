#include <iostream>
using namespace std;

float fah(float temp)
{
    return 1.8*temp+32.0;
}
int main()
{
    cout<<"Please enter a Celsius value:";
    float temp;
    cin >> temp;
    cout <<temp<< " degrees Celsius is "<<fah(temp)<<" degrees Fahrenheit.\n" ;
    return 0;
}