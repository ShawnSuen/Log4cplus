#ifndef LOGGER_INCLUDE
#define LOGGER_INCLUDE

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <deque>

#include "utils.h"
#include "loggermessage.h"


using namespace std;

class Logger
{

public:
	Utils utils;
	LoggerConfig logerConfig;
	deque<string> g_DSLoggerMessage;//����һ�����У�������������
	/*************************************************************
	* ����:     ��ʼ��Logger��ķ���
	* ������:   InitLogger
	* ��: public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	*  	       
	* �汾��ʷ
	*1.0 2020/08/28     ��۸�ʵ�ֹ���
	*************************************************************/
	void InitLogger();

	/*************************************************************
	* ����:     �ر�Logger��ķ���
	* ������:   CloseLogger
	* ��: public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	*
	* �汾��ʷ
	*1.0 2020/08/28     ��۸�ʵ�ֹ���
	*************************************************************/
	void CloseLogger();


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
	void Debug(char* pMessage,int nLine, char* pFileWithLogger);

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
	void Info(char* pMessage, int nLine, char* pFileWithLogger);

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
	void Warning(char* pMessage, int nLine, char* pFileWithLogger);

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
	void Error(char* pMessage, int nLine, char* pFileWithLogger);

	/*************************************************************
	* ����:     ��LoggerMessage����ת�����ַ��������������
	* ������:   Logger2String
	* ��:		private
	* ����ֵ:   string strLoggerMessage:LoggerMessage����ת���ɵ��ַ���
	* �����б� 	       ��������           		����
	* loggerMessage 	   LoggerMessage			�����Ӧ��LoggerMessage����
	* �汾��ʷ
	*1.0 2020/08/28     ��۸�ʵ�ֹ���
	*************************************************************/
	std::string Logger2String(LoggerMessage loggerMessage);


private:
	LoggerMessage GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent,int nLine, std::string strFileWithLogger);
};
#define DEBUG(message) Debug(message,__LINE__,__FILE__)

#define INFO(message) Info(message,__LINE__,__FILE__)

#define WARNING(message) Warning(message,__LINE__,__FILE__)

#define ERROR(message) Error(message,__LINE__,__FILE__)

#endif


