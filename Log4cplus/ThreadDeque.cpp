#ifndef THREADDEQUE_STL
#define THREADDEQUE_STL
#include "ThreadDeque.h"
#include <string>
#include<iostream>
using namespace std;
deque<deque<string>> ddsNumDeque;   //定义一个存放队列的队列
mutex mu;               //定义一个锁
condition_variable cond;//定义一个条件变量

/*************************************************************
* 概述:      将Log需要打印的内容push进队列
* 函数名:   LoggerPushThread()
* 属性:     public
* 返回值:   void
* 参数列表： 	       参数类型           取值范围描述
* strPush              string           log日志push进队列的内容
* 版本历史
*1.0  2020/08/27     将Log需要打印的内容push进队列
*************************************************************/
void ThreadDeque::LoggerPushThread(deque<string> dsLogger)
{   
	std::unique_lock<std::mutex> locker(mu); //上锁
	ddsNumDeque.push_front(dsLogger);//str类型日志内容push进队列
	locker.unlock();//释放锁

	cond.notify_one();  // Notify one waiting thread, if there is one.
	std::this_thread::sleep_for(std::chrono::seconds(1));
	
}


/*************************************************************
	* 概述:     将Log需要打印的内容pop出队列
	* 函数名:   LoggerPopThread()
	* 属性:     public
	* 返回值:   void
	* 参数列表： 	       参数类型           取值范围描述
	*
	* 版本历史
	*1.0  2020/08/27     将Log需要打印的内容pop出队列
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