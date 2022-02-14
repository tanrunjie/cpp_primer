#include <iostream>
const int Limit = 255;

using namespace std;

int main()
{
    char input[Limit];

    cout <<"Enter a string for getline() processing:" << endl;
    cin.getline(input, Limit, '#'); // discard #
    cout <<"Here is your input:" << endl;
    cout <<input <<"\nDone with phase 1\n";

    char ch;
    cin.get(ch);
    cout <<"The next input character is " << ch << endl;

    if(ch!='\n')
        cin.ignore(Limit, '\n');
    
    cout <<"Enter a string for get() processing: " << endl;
    cin.get(input, Limit, '#');
    cout << "Here is your input:" << endl;
    cout << input <<"\nDone wht phase 2\n";

    cin.get(ch);
    cout <<"The next input character is " << ch << endl;

    return 0;
}