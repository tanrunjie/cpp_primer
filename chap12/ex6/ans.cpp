// 12-6
#include <iostream> 
#include <cstdlib>    // rand(), srand(), RAND_MAX
#include <ctime>      // time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);   // 判断是否有新用户到来

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	std::srand(std::time(0));  // 随机初始化rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line1(qs);
	Queue line2(qs);

	cout << "Enter the number of simulation hours (no less than 100): ";
	int hours;
	cin >> hours;
	// 循环每1分钟运行一次
	long cyclelimit = MIN_PER_HR * hours;

	//cout << "Enter the average number of customers per hour: ";
	//double perhour;
	//cin >> perhour;
	//double min_per_cust;
	//min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;           // 因满队列而拒绝接收的人数
	long customers = 0;           // 加入队列的数量
	long served = 0;              // 仿真期间服务的人数
	long sum_line = 0;            // 累计队列长度
	int wait_time1 = 0;           // 自动存取机1的空闲时间
	int wait_time2 = 0;           // 自动存取机2的空闲时间
	int line1_size = 0;           // 队列1当前长度
	int line2_size = 0;           // 队列2当前长度
	long line_wait = 0;           // 累计在队列中的时间
	double avg_wait_time = 0.0;   // 顾客平均等待时间

	// 每小时使用人数初始值设为15，之后进行+1枚举测试
	double perhour = 15;
	double min_per_cust;

	// 仿真开始
	do {
		min_per_cust = MIN_PER_HR / perhour;
		turnaways = 0;           // 因满队列而拒绝接收的人数
		customers = 0;           // 加入队列的数量
		served = 0;              // 仿真期间服务的人数
		sum_line = 0;            // 累计队列长度
		wait_time1 = 0;            // 自动存取机1的空闲时间
		wait_time2 = 0;
		line1_size = 0;
		line2_size = 0;
		line_wait = 0;           // 累计在队列中的时间
		avg_wait_time = 0.0;   // 顾客平均等待时间

	    // 清空队列
		while (!line1.isempty())
			line1.dequeue(temp);
		while (!line2.isempty())
			line2.dequeue(temp);

		for (int cycle = 0; cycle < cyclelimit; cycle++) {
			if (newcustomer(min_per_cust))   // 有新顾客到来
			{
				if (line1.isfull() && line2.isfull())
					turnaways++;
				else if(line1_size > line2_size){
					customers++;
					temp.set(cycle);          // cycle = time of arrival
					line2.enqueue(temp);
					line2_size++;
				}
				else {
					customers++;
					temp.set(cycle);
					line1.enqueue(temp);
					line1_size++;
				}
			}
			if (wait_time1 <= 0 && !line1.isempty()) {
				line1.dequeue(temp);  // 下一个客户
				line1_size--;
				wait_time1 = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time2 <= 0 && !line2.isempty()) {
				line2.dequeue(temp);  // 下一个客户
				line2_size--;
				wait_time2 = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time1 > 0)
				wait_time1--;
			if (wait_time2 > 0)
				wait_time2--;
			sum_line += line1.queuecount();
			sum_line += line2.queuecount();
		}

		// 报告结果
		if (customers > 0) {
			cout << "custormers accepted: " << customers << endl;
			cout << "   customers served: " << served << endl;
			cout << "          turnaways: " << turnaways << endl;
			cout << " average queue size: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << double(sum_line / cyclelimit) << endl;
			avg_wait_time = double(line_wait / served);
			cout << "  average wait time: " << avg_wait_time << " minutes\n";
		}
		else
			cout << "No customers!\n";
	} while ((perhour++) && ((avg_wait_time < 0.9) || (avg_wait_time > 1.1)));

	cout << "When perhour = " << perhour << ", the average wait time will be about 1 minute.\n";
	cout << "Done!\n";
	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}