#ifndef THREADDEQUE_INCLUDE
#define THREADDEQUE_INCLUDE

#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

#include "loggermessage.h"
#include "ManageLog.h"
using namespace std;
class ThreadManager
{
	ManageLog manageLog;
	LoggerConfig g_loggerConfig;
public:

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
	LoggerConfig ReadLoggerManager();

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
	void WriteLogger2File(deque<string> dsLoggerMessage);

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
	void WriteLogger2Console(deque<string> dsLoggerMessage);

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
	void ClearLogFile();

};

#endif



