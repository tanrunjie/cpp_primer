#include <iostream>
#include "port.h"
using namespace std;

int main()
{
    Port p1("daxixiong","fried",20);
    cout << (p1+=20) << endl;

    VintagePort vp1("hanbaowang",60,"hbw",2022);
    VintagePort vp2(vp1);
    vp1.Show();
    cout << vp2 << endl;

    return 0;
}