#ifndef LOGGER_INCLUDE
#define LOGGER_INCLUDE

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "loggermessage.h"

//TODO : �����logger��־�У���ȡloggerʵ����ʱ���ڵ��ļ�������

class Logger
{

public:

	/*************************************************************
	* ����:     ����һ��Debug��־��������־��ʱ�䡢�ȼ�����Ϣ
	* ������:   Log
	* ��		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	* pMessage			   char*					������־����Ϣ
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/
	void Debug(char* pMessage);

	/*************************************************************
	* ����:     ����һ��Info��־��������־��ʱ�䡢�ȼ�����Ϣ
	* ������:   Log
	* ��		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	* pMessage			   char*					������־����Ϣ
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/
	void Info(char* pMessage);

	/*************************************************************
	* ����:     ����һ��Warning��־��������־��ʱ�䡢�ȼ�����Ϣ
	* ������:   Log
	* ��		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	* pMessage			   char*					������־����Ϣ
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/
	void Warning(char* pMessage);

	/*************************************************************
	* ����:     ����һ��Error��־��������־��ʱ�䡢�ȼ�����Ϣ
	* ������:   Log	
	* ��		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	* pMessage			   char*					������־����Ϣ
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/
	void Error(char* pMessage);

	/*************************************************************
	* ����:     TODO
	* ������:   Log	
	* ��		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	* pMessage			   char*					������־����Ϣ
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/
	void Init();

private:
	LoggerMessage m_LoggerMessage;

	void GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent);
};
#endif
