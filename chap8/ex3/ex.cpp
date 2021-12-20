#include <iostream>
#include <string>

using namespace std;

void tou(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
}
int main()
{
    cout << "Enter a string (q to quit): ";
    string str;
    while (getline(cin,str))
    {
        
        if (str == "q")
            break;
        else
        {
            tou(str);
            cout << str << endl;
        }
        cout <<"Next string (q to quit):";
    }
    cout <<"Bye.\n";
    return 0;
}