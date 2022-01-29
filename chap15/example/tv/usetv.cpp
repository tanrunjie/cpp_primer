#include <iostream>
#include "tv.h"

using namespace std;

int main()
{
    Tv s27;
    cout <<"Initial settings for 27\" TV:\n";
    s27.settings();
    s27.onoff();
    s27.chanup();
    cout <<"\nAdjusted settings for 27\" TV:\n";
    s27.settings();

    Remote grey;

    
    return 0;
}