#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>
#include <future>
using namespace std;

mutex mu;

int factorial(future<int>& f)
{
    int res = 1;

    int N = f.get();
    for (int i = N; i > 1; i--)
        res *= i;

    cout << "Result is:" << res << endl;
    return res;
}

int main()
{
    int x;
    promise<int> p;
    future<int> f = p.get_future();
    future<int> fu = async(factorial, ref(f)); // 创建自线程

    p.set_value(4);
    x = fu.get();

    cout <<"get from child:" << x <<endl;
    return 0;
}