#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    char first[80];
    char last[80];
    cout <<"Enter your first name: ";
    cin >> first;
    cout <<"Enter your last name: ";
    cin >> last;
    char con[3] = ", ";
    
    char full[162];
    strcpy(full,last);
    strcat(full, con);
    strcat(full, first);
    cout <<"Here's the information in a single string: " << full << endl;

    return 0;
}