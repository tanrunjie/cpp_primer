#include <iostream>
#include "stringbad.h"

using namespace std;

void callme1(StringBad &rsb)
{
    cout << "String passed by reference: \n";
    cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value: \n";
    cout << "   \"" << sb << "\"\n";
}

const int ArSize = 10;
const int MaxLen = 81;
int main()
{
    // StringBad headline1("Celery Stalks at Midnight");
    // StringBad headline2("Lettuce Prey");
    // StringBad sport("Spinach Leaves Bowl for Dollars");
    // cout <<"h1:" << headline1 << endl;
    // cout <<"h2:" << headline2 << endl;
    // cout <<"sports: " << sport << endl;

    // callme1(headline1);
    // cout <<"h1: " << headline1 << endl;
    // callme2(headline2);  // bypass value make big errors!!!
    // cout <<"h2: " << headline2 << endl;
    // cout <<"Initialize one object to another: \n";
    // StringBad sailor = sport; // 隐式构造引起计数问题
    // cout <<"sailor: " << sailor << endl;
    // cout <<"Assign one object to another: \n";
    // StringBad knot;
    // knot = headline1; //隐式赋值引起计数问题
    // cout <<"knot: " << knot << endl;
    // cout <<"End of main()\n";

    // StringBad answer = "love";
    // if("love"==answer)
    //     cout <<"succeeed" << endl;
    // cout << answer[1] << endl;
    // answer[1] = 'a';
    // cout << answer;

    StringBad name;
    cout << "Hi, what's your name?\n";
    cin >> name;
    cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";

    StringBad sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }
    int total = i;

    cout << "Here are your sayings:\n";
    for (i = 0; i < total; i++)
        cout << sayings[i][0] << ": " << sayings[i] << endl;

    int shortest = 0;
    int first = 0;
    for (i = 1; i < total; i++)
    {
        if (sayings[i].length() < sayings[shortest].length())
            shortest = i;
        if (sayings[i] < sayings[first])
            first = i;
    }
    cout << "Shortest sayings:\n"
         << sayings[shortest] << endl;
    cout << "First alphabetically:\n"
         << sayings[first] << endl;
    cout << "This program used " << StringBad::HowMany() << " StringBad objects. Bye/\n";

    return 0;
}