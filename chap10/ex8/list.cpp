#include "list.h"

List::List()
{
}
void List::push(int n)
{
    vec.push_back(n);
}
bool List::isempty() const
{
    return vec.size() == 0;
}
bool List::isfull() const
{
    return vec.size() == List::max_num;
}

void List::iter_mul2()
{
    for (int i = 0; i < vec.size(); i++)
        vec[i] = vec[i] * 2;
}

void List::show() const
{
    for (int i = 0; i < vec.size(); i++)
        cout <<vec[i] << " ";
    cout << endl;
}