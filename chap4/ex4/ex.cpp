#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string first, last;
    cout <<"Enter your first name: ";
    cin >> first;
    cout <<"Enter your last name: ";
    cin >> last;

    cout <<"Here's the information in a single string: " << last+", "+first << endl;

    return 0;
}