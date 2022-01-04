#include "list.h"

int main()
{
    List l;
    cout << l.isempty() << endl;
    cout << l.isfull() << endl;
    for(int i=0; i<5;i++)
        l.push(i);
    l.show();


    l.iter_mul2();
    l.show();

    return 0;
}