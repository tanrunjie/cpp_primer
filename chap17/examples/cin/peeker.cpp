#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    char ch;
    while(cin.get(ch))
    {
        if(ch != '#')
            cout << ch;
        else
        {
            cin.putback(ch);
            break;
        }
    }

    if(!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << " is next input character." << endl;
    }
    else
    {
        cout <<"End of file reached." << endl;
        exit(0);
    }

    while(cin.peek() != '#')
    {
        cin.get(ch);
        cout << ch;
    }
    if(!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << " is next input character." << endl;
    }
    else
        cout <<"End of file reached." << endl;

    return 0;
}