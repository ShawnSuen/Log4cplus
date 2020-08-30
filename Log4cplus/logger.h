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
	* ����:     ����logger��ʹ�á��ڴ˷����а����˶�ȡlogger�����ļ�
	*		����Ҳ���õ��̵߳ķ�ʽ�����ó���
	* ������:   Init
	* ��:		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	*
	* �汾��ʷ
	*1.0 2020/08/28     ��۸�ʵ�ֹ���
	*************************************************************/
	void InitLogger();

	/*************************************************************
	* ����:     ����loggerʹ�ã����а����˽����ݻ�������logger����
	*		�ֱ�д�뵽logger�ļ��С�����̨���Լ���ʱ����logger�ļ�
	*		��֤log�ļ�������������ࡣͬʱ�����������߳���ʵ���첽
	*		��д���ɾ������С�������̵߳�Ӱ�졣
	* ������:   CloseLogger
	* ��:		public
	* ����ֵ:   void
	* �����б�:
	*
	* �汾��ʷ
	* 1.0 		2020/08/30     ��۸�ʵ�ֹ���
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
	/*************************************************************
	* ����:     ����һ��logger��־
	* ������:   GenerateLoggerMessage
	* ��:		public
	* ����ֵ:   LoggerMessage loggerMessage: ��Ӧ�����Ѿ���ֵ���logger����
	* �����б�:
	* string strLoggerRank:	log��־�ĵȼ�
	* string strLoggerContent:	log��־������
	* int nLine: ʹ��log������־��¼ʱ����Ӧ������ڵĴ�������
	* string strFileWithLogger: ʹ��log������־��¼ʱ����Ӧ������ڵ��ļ���
	* �汾��ʷ
	* 1.0 		2020/08/30     ��۸�ʵ�ֹ���
	*************************************************************/
	LoggerMessage GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent,int nLine, 
		std::string strFileWithLogger);
};

//����һ��DEBUG�꣬ʵ�ֶ�Debug�����ĵ���
#define DEBUG(message) Debug(message,__LINE__,__FILE__)

//����һ��INFO�꣬ʵ�ֶ�Info�����ĵ���
#define INFO(message) Info(message,__LINE__,__FILE__)

//����һ��WARNING�꣬ʵ�ֶ�Warning�ĵ���
#define WARNING(message) Warning(message,__LINE__,__FILE__)

//����һ��ERROR�꣬ʵ�ֶ�Error�ĵ���
#define ERROR(message) Error(message,__LINE__,__FILE__)

#endif


