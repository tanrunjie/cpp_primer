#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <thread>
#include <deque>
#include <condition_variable>

using namespace std;

deque<int> q;
mutex mu;
condition_variable cond;  // 条件变量
// 生产者
void function_1()
{
    int count = 10;
    while(count > 0)
    {
        unique_lock<mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        cond.notify_one();
        this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}

// 消费者：条件变量
void function_2()
{
    int data = 0;
    while(data!=1)
    {
        unique_lock<mutex> locker(mu);
        cond.wait(locker, [](){ return !q.empty(); }); // 只能搭配unique_lock使用，用Lambda函数避免自解锁
        data = q.back();
        q.pop_back();
        locker.unlock();
        cout <<"t2 got a value from t1: " << data<<endl;
    }
}

/* 不优雅
void function_2()
{
    int data = 0;
    while(data!=1)
    {
        unique_lock<mutex> locker(mu);
        if(!q.empty())
        {
            data = q.back();
            q.pop_back();
            locker.unlock();
            cout <<"t2 got a value from t1: " << data<<endl;
        }
        else {
            locker.unlock();
            // this_thread::sleep_for(chrono::milliseconds(10));  若无数据，一直解锁locker;此时加入sleep缓解不停释放的行为
        }
    }
}
*/

int main()
{
    thread t1(function_1);
    thread t2(function_2);
    t1.join();
    t2.join();
    return 0;

}
