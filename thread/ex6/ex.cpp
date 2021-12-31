#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>
#include <future>
#include <ctime>
using namespace std;

mutex mu;

int factorial(shared_future<int> f)
{
    int res = 1;

    int N = f.get(); // 抛出异常， future_errc::broken_promise
    for (int i = N; i > 1; i--)
    {
        res += i;
    }    


    // cout << "Result is:" << res << endl;
    return res;
}

int main()
{
    int x;
    promise<int> p;
    future<int> f = p.get_future();
    shared_future<int> sf = f.share();

    clock_t start = clock();

    // 多线程并行(效率反而下降了～)
    future<int> fu0 = async(launch::async, factorial, sf); // 值传递
    // future<int> fu1 = async(launch::async, factorial, sf);
    // future<int> fu2 = async(launch::async, factorial, sf);
    // future<int> fu3 = async(launch::async, factorial, sf);
    // future<int> fu4 = async(launch::async, factorial, sf);
    p.set_value(4000);

    x = fu0.get();

    cout << "get from child:" << x << endl;
    clock_t end = clock();
    cout << "spend " << (double)(end - start) / CLOCKS_PER_SEC << "second" << endl;
    return 0;
}