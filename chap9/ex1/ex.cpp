#include <iostream>
#include "golf.h"
using namespace std;

extern const int Len;
int main()
{
    const int max_num = 3;
    golf *pg = new golf[max_num];

    char name[Len];
    int handicap;
    int i = 0;
    while (1)
    {
        cin >> name;
        if (strlen(name) == 0 || i > 1)
            break;
        cin >> handicap;

        golf ann;
        setgolf(ann, name, handicap);
        showgolf(ann);

        sethandicap(ann, 10);
        showgolf(ann);
        i++;
    }
    return 0;
}