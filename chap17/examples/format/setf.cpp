#include <iostream>
using namespace std;

int main()
{
    int temperature = 63;
    cout << "Today's water temperature: ";
    cout.setf(ios_base::showpos);
    cout << temperature << endl;

    cout <<"For our programming friends, that's " << endl;
    cout << hex << temperature << endl;

    cout.setf(ios_base::uppercase);
    cout.setf(ios_base::showbase);
    cout <<"or" << endl;
    cout << temperature << endl;
    cout <<"How " << true <<"!  oops - How ";
    cout.setf(ios_base::boolalpha);
    cout << true << endl;
    return 0;
}