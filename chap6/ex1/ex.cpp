#include <iostream>
#include <cctype>
int main()
{
    using namespace std;
    char ch;
    while(cin.get(ch) && ch!='@')
    {
        if(isdigit(ch))
            continue;
        else if(isupper(ch))
            cout << char(tolower(ch));
        else if(islower(ch))
            cout << char(toupper(ch));
    }
    return 0;
}