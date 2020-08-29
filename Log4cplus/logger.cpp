#ifndef LOGGER_STL
#define LOGGER_STL

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <io.h>
#include <stdio.h>
#include <process.h>
#include <thread>

#include "logger.h"
#include "loggermessage.h"
#include "ThreadDeque.h"
#include "ManageLog.h"
#include "utils.h"
ThreadDeque g_ThreadDeque;
Utils utils;
using namespace std;

/*************************************************************
* ����:     ��ʼ��logger
* ������:   Init
* ��:
* ����ֵ:   void
* �����б� 	       ��������           		����
*
* �汾��ʷ
*1.0 2020/08/28     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::InitLogger()
{

	//TODO������log�Ƿ�д�뵽logger�ļ���

	//TODO:����log�ļ��Ĵ洢·��

	//TODO:����log�ļ�����������

	//TODO:����log�ļ��Ĵ�С

	//TODO:�����Ƿ�ͨ������̨���


}


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
std::string Logger::Logger2String(LoggerMessage loggerMessage)
{
	string strLoggerMessage = loggerMessage.GetTime() + "  " +
		to_string(loggerMessage.GetLoggerPid()) + "|" +
		loggerMessage.GetLoggerRank() + "|" +
		to_string(loggerMessage.GetLoggerTid()) + "|" +
		loggerMessage.GetFileWithLogger() + ":" +
		std::to_string(loggerMessage.GetLineWithLogger()) + "    " +
		loggerMessage.GetLoggerContent();
	return strLoggerMessage;
}

/*************************************************************
* ����:     ʵ����Logger������ɶ�Logger��������Խ��и�ֵ
* ������:   GenerateLoggerMessage
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* strLoggerRank 	   string					����logger�ĵȼ�
* strLoggerContent	   string					����logger������
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
LoggerMessage Logger::GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent, int nLine, std::string strFileWithLogger)
{

	stringstream ssThreadId;
	ssThreadId << std::this_thread::get_id();
	int nLoggerTid;
	if (ssThreadId)
	{
		string strStream2String;
		strStream2String = ssThreadId.str();
		int nString2Long = stoi(strStream2String);
		nLoggerTid = nString2Long;
	}
	else
	{
		nLoggerTid = 0;
	}

	LoggerMessage loggerMessage;
	loggerMessage.SetTime(utils.GetLocalSystemTime());
	loggerMessage.SetLoggerPid(_getpid());
	loggerMessage.SetLoggerRank(strLoggerRank);
	loggerMessage.SetLoggerTid(nLoggerTid);
	loggerMessage.SetFileWithLogger(strFileWithLogger);
	loggerMessage.SetLineWithLogger(nLine);
	loggerMessage.SetLoggerCotent(strLoggerContent);
	return loggerMessage;
}

/*************************************************************
* ����:     ����һ��Debug��־��������־��ʱ�䡢�ȼ�����Ϣ
* ������:   Log
* ��		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* pMessage			   char*					������־����Ϣ
* inLine			   int						������־ʹ�õ��к�
* pFileWithLogger	   char*					������־ʹ�õ�����
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Debug(char* pLoggerContent, int nLine, char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Debug", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);
	cout << strLogger << endl;
	//����־д�뵽������
	g_DSLoggerMessage.push_back(loggerMessage);
}
/*************************************************************
* ����:     ����һ��Info��־��������־��ʱ�䡢�ȼ�����Ϣ
* ������:   Info
* ��		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* pMessage			   char*					������־����Ϣ
* inLine			   int						������־ʹ�õ��к�
* pFileWithLogger	   char*					������־ʹ�õ�����
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Info(char* pLoggerContent, int nLine, char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Info", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);
	cout << strLogger << endl;
	//����־д�뵽������
	g_DSLoggerMessage.push_back(loggerMessage);
}

/*************************************************************
* ����:     ����һ��Warning��־��������־��ʱ�䡢�ȼ�����Ϣ
* ������:   Warning
* ��		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* pMessage			   char*					������־����Ϣ
* inLine			   int						������־ʹ�õ��к�
* pFileWithLogger	   char*					������־ʹ�õ�����
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Warning(char* pLoggerContent, int nLine, char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Warning", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);
	cout << strLogger << endl;
	//����־д�뵽������
	g_DSLoggerMessage.push_back(loggerMessage);
}

/*************************************************************
* ����:     ����һ��Error��־��������־��ʱ�䡢�ȼ�����Ϣ
* ������:   Error
* ��		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* inLine			   int						������־ʹ�õ��к�
* pFileWithLogger	   char*					������־ʹ�õ�����
* pMessage			   char*					������־����Ϣ
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Error(char* pLoggerContent, int nLine, char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Error", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);
	cout << strLogger << endl;
	//����־д�뵽������
	g_DSLoggerMessage.push_back(loggerMessage);
}


#endif