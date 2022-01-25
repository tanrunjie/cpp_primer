#include <iostream>
#include "classic.h"

using namespace std;

void Bravo(const Cd & disk)
{
    disk.Report();
}
int main()
{
    Cd c1((char*)"Beatles", (char*)"Capitol", 14, 35.5);
    Classic c2 = Classic((char*)"Piano Sonata in B flat, Fantasia in C",
    (char*)"Alfred Brendel", (char*)"Philips", 2, 57.17);

    Cd *pcd = &c1;
    cout <<"Using object directly:" << endl;
    c1.Report();
    c2.Report();

    cout <<"***********************************" << endl;
    cout <<"Using type cd * pointer to objects:" << endl;
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout <<"***********************************" << endl;
    cout <<"Calling a function with a Cd reference argument:" << endl;
    Bravo(c1);
    Bravo(c2);

    cout <<"Testing assignment:" << endl;
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}