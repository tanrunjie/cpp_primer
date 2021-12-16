#include <iostream>
#include <climits>
using namespace std;

int main()
{
    cout <<"Input your height:_(Inch)"<<endl;
    float height;
    cin >> height;

    const int inch_per_ft = 12;
    cout << "Your height is " <<height/float(12) << "ft" << endl;
}