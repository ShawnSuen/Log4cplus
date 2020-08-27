#include "ThreadDeque.h"
#include <iostream>
using namespace std;
void ThreadDeque::NumPushThread() {
	int count = 50;
	while (count > 0) {
		std::unique_lock<std::mutex> locker(mu); //上锁
		n_numdeque.push_front(count);//50个数循环push进队列
		cout << "push进队列的数：" << count << endl;
		locker.unlock();//释放锁

		cond.notify_one();  // Notify one waiting thread, if there is one.
		std::this_thread::sleep_for(std::chrono::seconds(1));
		count--;
	}
}

void ThreadDeque::NumPopThread() {
	int data = 0;
	while (data != 1) {
		std::unique_lock<std::mutex> locker(mu);
		while (n_numdeque.empty())
		{
			cond.wait(locker);
		} // Unlock mu and wait to be notified

		data = n_numdeque.back();
		n_numdeque.pop_back();
		locker.unlock();
		std::cout << "t2 got a value from t1(pop得到的数：）: " << data << std::endl;
	}
}
