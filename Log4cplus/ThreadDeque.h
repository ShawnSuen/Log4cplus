#ifndef THREADDEQUE_INCLUDE
#define THREADDEQUE_INCLUDE
/*********************************************************************
 *
 *  文      件:    ThreadDeque.h   interface for the XXX class.
 *
 *  版权所有:      Shanghai Baosight Software WYS.
 *
 *  概述：	     利用多线程的互斥变量和条件变量实现对队列进行多线程的同步和互斥操作。
 *               队列存储的内容为Log需要打印的数据      
 *
 *
 *  版本历史
 *      1.0        2020-8-27    XXXXXX      创建：王永生
 *
*********************************************************************/
#include <iostream>
#include <deque>
#include <thread>
#include <mutex>


#include <condition_variable>
using namespace std;
class ThreadDeque
{
public:
	
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
	void LoggerPushThread(deque<string> dsLogger);




/*************************************************************
	* 概述:     将Log需要打印的内容pop出队列
	* 函数名:   LoggerPopThread()
	* 属性:     public
	* 返回值:   string
	* 参数列表： 	       参数类型           取值范围描述
	* strNumDeque         deque<string>      缓冲log日志内容的队列
	* 版本历史
	*1.0  2020/08/27     将Log需要打印的内容pop出队列
*************************************************************/
	/*string  NumPopThread();*/
	void  LoggerPopThread();

	deque<deque<string>> GetDeque();

};

#endif



