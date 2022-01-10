#include <iostream>
#include "cow.h"

using namespace std;
int main()
{
    Cow c1("ryan", "tan", 70.0);
    c1.ShowCow();
    Cow c2("shanshan", "ho", 50.0);
    c2 = c1;
    c2.ShowCow();
    Cow c3(c2);
    Cow c4 = c1;
    c3.ShowCow();
    c4.ShowCow();
    return 0;
}