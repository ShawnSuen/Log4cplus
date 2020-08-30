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
mutex g_Mutex;               //����һ����
condition_variable g_cond;//����һ����������

string m_StrFileFullPath = "";
bool m_BReadLoggerConfig = false;
LoggerConfig m_LoggerConfig;

/*************************************************************
* ����:     ��ȡLogger�����ļ���������ȡ������Ϣ��װ��������
* ������:   ReadLoggerManager
* ��:		public
* ����ֵ:   LoggerConfig m_LoggerConfig
* �����б�:
*   	       
* �汾��ʷ
* 1.0 		2020/08/30     ��۸�ʵ�ֹ���
*************************************************************/
LoggerConfig ThreadManager::ReadLoggerManager()
{
	std::unique_lock<std::mutex> locker(g_Mutex); //����
	m_LoggerConfig = manageLog.GetLoggerConfig();
	if (m_LoggerConfig.GetLoggerFilePath() != "")
	{
		m_StrFileFullPath = manageLog.CreateLogFile(m_LoggerConfig.GetLoggerFilePath());

		locker.unlock();//�ͷ���
		g_cond.notify_one();  // Notify one waiting thread, if there is one.
		m_BReadLoggerConfig = true;
	}
	return m_LoggerConfig;

}

/*************************************************************
* ����:     ��logger��־д�뵽logger�ļ�
* ������:   WriteLogger2File
* ��:		public
* ����ֵ:   void
* �����б�:
* deque<string> dsLoggerMessage: д�����̨��Ŀ����� 	       
* �汾��ʷ
* 1.0 		2020/08/30     ��۸�ʵ�ֹ���
*************************************************************/
void ThreadManager::WriteLogger2File(deque<string> dsLoggerMessage)
{
	std::unique_lock<std::mutex> locker(g_Mutex); //����
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
* ����:     ��logger��־���������̨���߳�
* ������:   WriteLogger2Console
* ��:		public
* ����ֵ:   void
* �����б�:
* deque<string> dsLoggerMessage: д�����̨��Ŀ����� 	       
* �汾��ʷ
* 1.0 		2020/08/31     ��۸�ʵ�ֹ���
*************************************************************/
void ThreadManager::WriteLogger2Console(deque<string> dsLoggerMessage)
{
	std::unique_lock<std::mutex> locker(g_Mutex); //����
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
* ����:     ����log�ļ�������log�ļ�����������������
* ������:   ClearLogFile
* ��:		public
* ����ֵ:   void
* �����б�:
*   	       
* �汾��ʷ
* 1.0 		2020/08/31     ��۸�ʵ�ֹ���
*************************************************************/
void ThreadManager::ClearLogFile()
{
		std::unique_lock<std::mutex> locker(g_Mutex); //����
		while (!m_BReadLoggerConfig)
		{
			g_cond.wait(locker);
		}
		manageLog.ClearLogFile(manageLog.FindLogFile(m_LoggerConfig.GetLoggerFilePath()), m_LoggerConfig.GetLoggerNum());
		locker.unlock();

}

#endif