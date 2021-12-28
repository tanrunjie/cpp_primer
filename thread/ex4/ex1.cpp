// lazy initialization
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>
using namespace std;

// 所占用的资源
class LofFile
{
public:
    LofFile()
    {
        // f.open("log.txt");
    }
    void shared_print(string id, int value)
    {

        // {
        //     // 每次调用都需创建一个锁和检测以及释放
        //     unique_lock<mutex> locker(m_mutex, defer_lock);
        //     if (!f.is_open())
        //     {
        //         f.open("log.txt");
        //     }
        // }
        call_once(m_flag,[&](){f.open("log.txt"); }); // once_flag + lambda func
        unique_lock<mutex> locker(m_mutex, defer_lock);
        f << id << value << endl;
    }

private:
    mutex m_mutex;
    ofstream f;
    once_flag m_flag;
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
        log.shared_print("From main: ", i);

    t1.join();
    return 0;
}