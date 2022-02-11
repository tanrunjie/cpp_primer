#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool ifplalindrome(string & s)
{
    string res;
    if(s.size()<2)
        return true;
    remove_copy_if(s.begin(),s.end(),back_inserter(res),ptr_fun<int, int>(&ispunct));
    for(int i=0; i<res.size();i++)
    {
            res[i] = tolower(res[i]);
    }
    for(int i=0;i<res.size()/2;i++)
    {
        if(res[i]!=res[res.size()-1-i])
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