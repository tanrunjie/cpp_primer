#include <iostream>
#include "stringbad.h"

using namespace std;

void callme1(StringBad & rsb)
{
    cout <<"String passed by reference: \n";
    cout <<"   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout <<"String passed by value: \n";
    cout <<"   \"" << sb << "\"\n";
}

int main()
{
    StringBad headline1("Celery Stalks at Midnight");
    StringBad headline2("Lettuce Prey");
    StringBad sport("Spinach Leaves Bowl for Dollars");
    cout <<"h1:" << headline1 << endl;
    cout <<"h2:" << headline2 << endl;
    cout <<"sports: " << sport << endl;

    callme1(headline1);
    cout <<"h1: " << headline1 << endl;
    callme2(headline2);  // bypass value make big errors!!!
    cout <<"h2: " << headline2 << endl;
    cout <<"Initialize one object to another: \n";
    StringBad sailor = sport; // 隐式构造引起计数问题
    cout <<"sailor: " << sailor << endl;
    cout <<"Assign one object to another: \n";
    StringBad knot;
    knot = headline1; //隐式赋值引起计数问题
    cout <<"knot: " << knot << endl;
    cout <<"End of main()\n";
    return 0;
}