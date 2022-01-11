#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int n)
{
    pitems = new Item[n];
    size = n;
    top = n;
}

Stack::Stack(const Stack & st)
{
    pitems = new Item[st.size];
    size = st.size;
    top = st.top;
    for(int i=0;i<size;i++)
        pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return size==0;
}
bool Stack::isfull() const
{
    return size==MAX;
}
bool Stack::push(const Item & item)
{
    if(isfull())
        return false;
    pitems[top] = item;
    top++;
    size++;
    return true;
}
bool Stack::pop(Item & item)
{
    if(isempty())
        return false;
    item = pitems[top-1];
    size--;
    top--;
    return true;
}
Stack & Stack::operator=(const Stack & st)
{
    if(this==&st)
        return *this;
    delete [] pitems;
    pitems = new Item[st.size];
    size = st.size;
    top = st.top;
     for(int i=0;i<size;i++)
        pitems[i] = st.pitems[i];
    return *this;
}
void Stack::show() const
{
    for(int i=0;i<size;i++)
        cout << pitems[i] <<" ";
    cout << endl;
}