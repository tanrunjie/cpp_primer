#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int cnt = 0;
    string s;
    char ch[255];
    cin.get(ch, 255, '$');
    cout << ch << endl;
    cout << strlen(ch) << endl;

    return 0;
}