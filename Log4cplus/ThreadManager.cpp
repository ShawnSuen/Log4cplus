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
	return g_loggerConfig;

}

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