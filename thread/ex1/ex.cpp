#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
class Fctor
{
public:
  void operator()(string msg)
  {
    cout << "from f1: " << msg << endl;
    msg = "text changed";
  }
};

int main()
{
  string s = "text not changed";
  cout << "main thread id: " << this_thread::get_id() << endl;
  thread t1((Fctor()), move(s));
  // t1.join();
  thread t2 = move(t1);
  cout << s << endl;
  cout << "thread1 id: " << t1.get_id() << endl;
  cout << "thread2 id: " << t2.get_id() << endl;
  t2.join();

  cout << "cores of current device: " << thread::hardware_concurrency() << endl;
  return 0;
}