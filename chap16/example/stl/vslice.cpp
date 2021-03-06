#include <iostream>
#include <valarray>
#include <cstdlib>

using namespace std;

const int SIZE = 12;
typedef valarray<int> vint;

void show(const vint &v, int cols)
{
    int lim = v.size();
    for (int i = 0; i < lim; i++)
    {
        cout.width(3);
        cout << v[i];
        if (i % cols == cols - 1)
            cout << endl;
        else
            cout << ' ';
    }
    if (lim % cols != 0)
        cout << endl;
}

int main()
{
    vint valint(SIZE);
    int i;
    for (i = 0; i < SIZE; i++)
        valint[i] = rand() % 10;
    cout << "Original array:" << endl;
    show(valint, 3);
    vint vcol(valint[slice(1, 4, 3)]);
    cout << "Second column:" << endl;
    show(vcol, 1);

    vint vrow(valint[slice(3, 3, 1)]); // offset, size, stride
    cout << "Second row:" << endl;
    show(vrow, 3);

    valint[slice(2,4,3)] = 10;
    cout <<"Set last column to 10:" << endl;
    show(valint,3);

    cout <<"Set first column to sum of next two:" << endl;
    valint[slice(0,4,3)] = vint(valint[slice(1,4,3)]) + vint(valint[slice(2,4,3)]);

    show(valint, 3);
    return 0;
}