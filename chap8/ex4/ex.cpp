#include <iostream>
using namespace std;
#include <cstring>
struct stringy{
    char *str;
    int ct;
};

void set(stringy& s, char* str)
{
    s.ct = strlen(str);
    s.str = new char[s.ct];
    s.str = str;
}

const void show(stringy &s) 
{
    cout << s.str <<endl;
}
const void show(const stringy &s, int times=3)
{
    for(int i=0; i<times; i++)
        cout << s.str;
    cout << endl;
}
const void show(char* str)
{
    cout <<str<<endl;
}
const void show(const char* str, int times=3)
{
    for(int i=0;i<times;i++)
        cout << str;
    cout << endl;
}

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be. ";

    set(beany,testing);
    show(beany);
    show(beany,2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing,3);
    show("Done!");
    return 0;
}