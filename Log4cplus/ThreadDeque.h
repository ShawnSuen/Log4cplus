#pragma once
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

class ThreadDeque
{
public:
/*************************************************************
* 概述:     将十个递减的数push进队列
* 函数名:   NumSubThread()
* 属性:     public
* 返回值:   void
* 参数列表： 	       参数类型           取值范围描述
*
* 版本历史
*1.0  2020/08/27     将Log需要打印的内容push进队列
*************************************************************/
	void NumPushThread();

/*************************************************************
	* 概述:     将十个递减的数push进队列
	* 函数名:   NumPopThread()
	* 属性:     public
	* 返回值:   void
	* 参数列表： 	       参数类型           取值范围描述
	*
	* 版本历史
	*1.0  2020/08/27     将Log需要打印的内容pop出队列
*************************************************************/
	void NumPopThread();


	std::deque<int> n_numdeque;   //定义一个队列
	std::mutex mu;               //定义一个锁
	std::condition_variable cond;//定义一个条件变量

};

