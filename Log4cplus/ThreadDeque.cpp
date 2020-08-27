#include "ThreadDeque.h"
#include <iostream>
using namespace std;
void ThreadDeque::NumPushThread() {
	int count = 50;
	while (count > 0) {
		std::unique_lock<std::mutex> locker(mu); //����
		n_numdeque.push_front(count);//50����ѭ��push������
		cout << "push�����е�����" << count << endl;
		locker.unlock();//�ͷ���

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
		std::cout << "t2 got a value from t1(pop�õ���������: " << data << std::endl;
	}
}
