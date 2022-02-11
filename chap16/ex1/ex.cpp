#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool ifplalindrome(string & s)
{
    if(s.size()<2)
        return true;

    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << "Is plalindrome? " <<ifplalindrome(s) << endl;

    return 0;

}