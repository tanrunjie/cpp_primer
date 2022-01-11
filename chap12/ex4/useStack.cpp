#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack s1;
    Stack s2(20);
    Item j;
    for(int i=0; i<10;i++)
    {
        s1.pop(j);
        cout << j << " ";
    }
    for(int i=0; i<8;i++)
        s1.push(Item(i));

    Stack s3(s1);
    s2 = s3;
    s3.show();
    s2.show();
}