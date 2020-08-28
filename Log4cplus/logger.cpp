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
#include <process.h>
#include <stdio.h>

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
* ����:     ��ȡ����ϵͳʱ��ʱ��
* ������:   getLocalTime
* ��:		public
* ����ֵ:   string strLocalTime
* �����б� 	       ��������           		����
* strLocalTime 	       string					���ر���ϵͳʱ��
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
std::string GetLocalTime() {
	std::stringstream strsStransTime;
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	strsStransTime << std::put_time(std::localtime(&t), "%Y-%m-%d %X");
	std::string strLocalTime;
	if (strsStransTime)
	{
		strLocalTime = strsStransTime.str();
		std::cout << strLocalTime << std::endl;
		return strLocalTime;
	}
	else
	{
		strLocalTime = "ERROR";
	}

	return strLocalTime;
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
	string strLoggerMessage = loggerMessage.GetTime() + "  " + loggerMessage.GetLoggerRank() + "|" +
		loggerMessage.GetFileWithLogger() + ":" + std::to_string(loggerMessage.GetLineWithLogger()) + "  " + loggerMessage.GetLoggerContent();
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
LoggerMessage Logger::GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent, int nLine,std::string strFileWithLogger)
{
	LoggerMessage loggerMessage;
	loggerMessage.SetTime(GetLocalTime());
	loggerMessage.SetLoggerRank(strLoggerRank);
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
void Logger::Debug(char* pLoggerContent,int nLine,char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Debug", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//����־д�뵽������
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

	//����־д�뵽������
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

	//����־д�뵽������
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

	//����־д�뵽������
}


#endif