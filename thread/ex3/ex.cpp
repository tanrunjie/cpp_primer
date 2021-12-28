// 教程：https://www.bilibili.com/video/BV1xt411r7U2?p=1

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>
using namespace std;

// 循环依赖产生的死锁
class LofFile
{
public:
    LofFile() {}

    void shared_print(string id, int value)
    {
        lock(m_mutex, m_mutex2);  
        lock_guard<mutex> locker(m_mutex, adopt_lock);
        lock_guard<mutex> locker2(m_mutex2, adopt_lock);
        cout << "From" << id << ": " << value << endl;
    }
    void shared_print2(string id, int value)
    {
        lock(m_mutex, m_mutex2); // 用lock确保互斥顺序一致

        lock_guard<mutex> locker2(m_mutex2, adopt_lock); // 若调换，则可避免
        lock_guard<mutex> locker(m_mutex, adopt_lock);
        cout << "From" << id << ": " << value << endl;
    }

private:
    mutex m_mutex;
    mutex m_mutex2;
    ofstream f; // 被m_mutex保护的对象
};

void function_1(LofFile &log)
{
    for (int i = 0; i > -100; i--)
        log.shared_print("From t1:", i);
}
int main()
{
    LofFile log;
    thread t1(function_1, ref(log));

    for (int i = 0; i < 100; i++)
        log.shared_print2("from main: ", i);

    t1.join();
    return 0;
}