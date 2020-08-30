#ifndef THREADDEQUE_STL
#define THREADDEQUE_STL

#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

#include "loggermessage.h"
#include "ManageLog.h"

#include "threadmanager.h"
using namespace std;
mutex g_Mutex;               //定义一个锁
condition_variable g_cond;//定义一个条件变量

string m_StrFileFullPath = "";
bool m_BReadLoggerConfig = false;
LoggerConfig m_LoggerConfig;

/*************************************************************
* 概述:     读取Logger配置文件，并将读取到的信息封装到对象内
* 函数名:   ReadLoggerManager
* 属:		public
* 返回值:   LoggerConfig m_LoggerConfig
* 参数列表:
*   	       
* 版本历史
* 1.0 		2020/08/30     孙港富实现功能
*************************************************************/
LoggerConfig ThreadManager::ReadLoggerManager()
{
	std::unique_lock<std::mutex> locker(g_Mutex); //上锁
	m_LoggerConfig = manageLog.GetLoggerConfig();
	if (m_LoggerConfig.GetLoggerFilePath() != "")
	{
		m_StrFileFullPath = manageLog.CreateLogFile(m_LoggerConfig.GetLoggerFilePath());

		locker.unlock();//释放锁
		g_cond.notify_one();  // Notify one waiting thread, if there is one.
		m_BReadLoggerConfig = true;
	}
	return m_LoggerConfig;

}

/*************************************************************
* 概述:     将logger日志写入到logger文件
* 函数名:   WriteLogger2File
* 属:		public
* 返回值:   void
* 参数列表:
* deque<string> dsLoggerMessage: 写入控制台的目标队列 	       
* 版本历史
* 1.0 		2020/08/30     孙港富实现功能
*************************************************************/
void ThreadManager::WriteLogger2File(deque<string> dsLoggerMessage)
{
	std::unique_lock<std::mutex> locker(g_Mutex); //上锁
	while (m_BReadLoggerConfig && dsLoggerMessage.empty() && m_StrFileFullPath != "")
	{
		g_cond.wait(locker);
	}
	if (m_LoggerConfig.GetOutput2LoggerFile())
	{
		manageLog.Write2LogFile(m_StrFileFullPath, dsLoggerMessage);
	}

	locker.unlock();
}

/*************************************************************
* 概述:     将logger日志输出到控制台的线程
* 函数名:   WriteLogger2Console
* 属:		public
* 返回值:   void
* 参数列表:
* deque<string> dsLoggerMessage: 写入控制台的目标队列 	       
* 版本历史
* 1.0 		2020/08/31     孙港富实现功能
*************************************************************/
void ThreadManager::WriteLogger2Console(deque<string> dsLoggerMessage)
{
	std::unique_lock<std::mutex> locker(g_Mutex); //上锁
	while (m_BReadLoggerConfig && dsLoggerMessage.empty() && m_StrFileFullPath != "")
	{
		g_cond.wait(locker);
	}
	if (m_LoggerConfig.GetOutput2Console())
	{
		manageLog.DefaultPrint2Console(dsLoggerMessage);
	}
	

	locker.unlock();
}

/*************************************************************
* 概述:     清理log文件，保持log文件数量在期望的数量
* 函数名:   ClearLogFile
* 属:		public
* 返回值:   void
* 参数列表:
*   	       
* 版本历史
* 1.0 		2020/08/31     孙港富实现功能
*************************************************************/
void ThreadManager::ClearLogFile()
{
		std::unique_lock<std::mutex> locker(g_Mutex); //上锁
		while (!m_BReadLoggerConfig)
		{
			g_cond.wait(locker);
		}
		manageLog.ClearLogFile(manageLog.FindLogFile(m_LoggerConfig.GetLoggerFilePath()), m_LoggerConfig.GetLoggerNum());
		locker.unlock();

}

#endif