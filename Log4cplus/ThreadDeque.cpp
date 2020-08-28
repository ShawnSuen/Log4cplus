#ifndef THREADDEQUE_STL
#define THREADDEQUE_STL
#include "ThreadDeque.h"
#include <string>
#include<iostream>
using namespace std;
deque<deque<string>> ddsNumDeque;   //����һ����Ŷ��еĶ���
mutex mu;               //����һ����
condition_variable cond;//����һ����������

/*************************************************************
* ����:      ��Log��Ҫ��ӡ������push������
* ������:   LoggerPushThread()
* ����:     public
* ����ֵ:   void
* �����б� 	       ��������           ȡֵ��Χ����
* strPush              string           log��־push�����е�����
* �汾��ʷ
*1.0  2020/08/27     ��Log��Ҫ��ӡ������push������
*************************************************************/
void ThreadDeque::LoggerPushThread(deque<string> dsLogger)
{   
	std::unique_lock<std::mutex> locker(mu); //����
	ddsNumDeque.push_front(dsLogger);//str������־����push������
	locker.unlock();//�ͷ���

	cond.notify_one();  // Notify one waiting thread, if there is one.
	std::this_thread::sleep_for(std::chrono::seconds(1));
	
}


/*************************************************************
	* ����:     ��Log��Ҫ��ӡ������pop������
	* ������:   LoggerPopThread()
	* ����:     public
	* ����ֵ:   void
	* �����б� 	       ��������           ȡֵ��Χ����
	*
	* �汾��ʷ
	*1.0  2020/08/27     ��Log��Ҫ��ӡ������pop������
*************************************************************/
void ThreadDeque::LoggerPopThread()
{
	while (!ddsNumDeque.empty())
	{		
		std::unique_lock<std::mutex> locker(mu);
		while (ddsNumDeque.empty())
		{
			cond.wait(locker);
		} // Unlock mu and wait to be notified
		deque<string> dsPop = ddsNumDeque.back();
		ddsNumDeque.pop_back();
		locker.unlock();
	}
}

deque<deque<string>> ThreadDeque::GetDeque()
{
	return ddsNumDeque;
}

#endif