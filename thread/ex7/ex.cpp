#include <iostream>
#include <thread>
#include <future>
#include <mutex>

using namespace std;

class A
{
public:
    void f(int x, char c) {cout << x << c << endl;}
    int operator()(int N) { 
        cout << N << endl;
        return 0; }
};

void foo(int x){cout << x <<endl;}

int main()
{
    // 线程创建及启动
    A a;
    // thread t1(a, 6);
    // thread t2(ref(a), 6);
    // thread t3(move(a), 6); // t1 失效
    // thread t4(A(), 6);
    // thread t5(foo, 6);
    // thread t6([](int x){cout<< x*x << endl; }, 6);
    // thread t7(&A::f, a, 8, 'w');
    thread t8(&A::f, &a, 8, 'w');
    
    // async(launch::async, a, 6); // similar to thread
    t8.join();
   

    return 0;
}