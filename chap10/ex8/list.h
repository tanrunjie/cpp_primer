#ifndef _LIST_H
#define _LIST_H
#include <vector>
#include <iostream>
using namespace std;
class List
{
    private:
        vector<int> vec;
        static const int max_num =5;
    public:
        List();
        void push(int n);
        bool isempty() const;
        bool isfull() const;

        void iter_mul2();
       
        void show() const;
};


#endif