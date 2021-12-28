#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>
using namespace std;

// lock_guard构建f单例，保证独占fout资源，从而保证线程安全
class LofFile
{
    public:
    LofFile(){
        f.open("log.txt");
    }
    void shared_print(string id, int value)
    {
        lock_guard<mutex> locker(m_mutex);
        f<< "From" << id <<": " << value << endl;
    }

    private:
        mutex m_mutex;
        ofstream f;
};
/*  cout资源为全局所有，即使加入互斥对象依然不能完全保护
mutex mu;
void shared_print(string msg, int id)
{
    lock_guard<mutex> guard(mu);
    // mu.lock();
    cout << msg << id << endl;
    // mu.unlock();
}
*/


void function_1(LofFile& log)
{
    for(int i=0; i>-100; i--)
        log.shared_print("From t1:",i);
}
int main()
{
    LofFile log;
    thread t1(function_1, ref(log));

    for(int i=0; i< 100; i++)
        log.shared_print("from main: ", i);

    t1.join();
    return 0;
}