#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct customer{
    char fullname[35];
    double payment;
};

class Stack{
    private:
        vector<customer> vec;
        int cnt;
        double sum;
    public:
        Stack(){ cnt=0; sum=0.0;}
        void push(customer c)
        {vec.push_back(c); cnt++; }
        void pop()
        {
            customer c;
            c = vec[vec.size()-1];
            vec.pop_back();
            sum += c.payment;
            cout << "sum: "<<sum<<endl;
            cnt--;
        }
};

int main()
{
    Stack s;
    customer c = {"tan runjie", 100.0};
    customer cc = {"ni menhao", 50.0};
    s.push(c);
    s.push(cc);
    s.pop();
    s.pop();

    return 0;
}