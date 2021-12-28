// unique_lock
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
    LofFile(){
        f.open("log.txt");
    }
    void shared_print(string id, int value)
    {
        // lock_guard<mutex> locker(m_mutex);  
        unique_lock<mutex> locker(m_mutex, defer_lock); // unique_lock占用更多系统资源
        // do_sth()  unlock
        // ...        

        locker.lock();
        f << id <<": " << value << endl;
        locker.unlock();
        // ...


        locker.lock(); // another unique_lock

        unique_lock<mutex> locker2 = move(locker);
    
    }

    private:
        mutex m_mutex;
        ofstream f;
};


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
        log.shared_print("From main: ", i);

    t1.join();
    return 0;
}