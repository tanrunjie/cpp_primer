#include <iostream>
#include "stringbad.h"

using namespace std;

int main()
{
    StringBad s1(" and I am a C++ student. ");
    StringBad s2("Please enter your name: ");
    StringBad s3;
    cout << s2;
    cin>>s3;
    
    s2 = "My name is ";
    s2 = s2 + s3;
    cout << s2 << ".\n";
    s2 = s2+ s1;
    s2.String();

    cout <<"The string\n"<< s2<< "\ncontains "<<s2.FindTimes('A') 
    <<"'A' characters in it.\n";

    s1 = "red";

    StringBad rgb[3] = {StringBad(s1), StringBad(" green"), StringBad("blue")};
    cout <<"Enter the name of a primary color for mixing light: ";
    StringBad ans;
    bool success = false;
    while(cin>>ans)
    {
        ans.Stringlow();
        for(int i=0;i<3;i++)
        {
            if(ans == rgb[i])
            {
                cout <<"That's right!\n";
                success = true;
                break;
            }
        }
        if(success)
            break;
        else
            cout<<"Try again!\n";
    }
    cout <<"Bye\n";
    return 0;
}