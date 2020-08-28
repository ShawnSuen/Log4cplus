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

ThreadDeque g_ThreadDeque;
using namespace std;
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
* ����:		�ָ��ַ���
* ������:	split
* ��:
* ����ֵ:   vector<string> result:���طָ����ַ���
* �����б� 	       ��������           ����
* s 				   string			  Ŀ���ַ���
* seperator			   string			  �ָ���
* �汾��ʷ
*1.0 2020/08/21     ��۸�ʵ�ֹ���
*************************************************************/
vector<string> split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//�ҵ��ַ������׸������ڷָ�������ĸ��
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}

		//�ҵ���һ���ָ������������ָ���֮����ַ���ȡ����
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
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
	vector<string> vsFilePath = split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Debug", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//����־д�뵽������
	g_DSLogger.push_back(strLogger);
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
	vector<string> vsFilePath = split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Info", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//����־д�뵽������
	g_DSLogger.push_back(strLogger);
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
	vector<string> vsFilePath = split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Warning", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//����־д�뵽������
	g_DSLogger.push_back(strLogger);
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
	vector<string> vsFilePath = split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Error", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//����־д�뵽������
	g_DSLogger.push_back(strLogger);
}


/*************************************************************
* ����:     FindLogFile
* ������:	FindLogFile
* ��:		public
* ����ֵ:   string
* �����б� 	       ��������           		����
* pAddr 			   char *					������Ҫ���ҵ��ļ�����
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
/*
std::vector<std::string> FindLogFile(const char* pAddr) {
	_finddata_t fileData;
	std::vector<std::string> vsLoggerFile;
	long handle = 0;
	handle = _findfirst(pAddr, &fileData);
	if (handle == -1) {
		return vsLoggerFile;
	}
	do {
		if (strcmp(fileData.name, "...") != 0 && strcmp(fileData.name, ". ") != 0) {
			vsLoggerFile.push_back(fileData.name);
		}
	} while (_findnext(handle, &fileData) == 0);
	_findclose(handle);
	return vsLoggerFile;
}

*/

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
void Logger::Init()
{
	Logger::g_DDSLogger = g_ThreadDeque.GetDeque();
	//������Ŷ��еĶ���

}
/*************************************************************
* ����:     XXXXX
* ������:   
* ��: 
* ����ֵ:   void
* �����б� 	       ��������           		����
*  	       
* �汾��ʷ
*1.0 2020/08/28     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Write2Deque()
{
	std::thread loggerThread(&ThreadDeque::LoggerPushThread, g_ThreadDeque, g_DSLogger);
	loggerThread.join();
}

/*************************************************************
* ����:     XXXXX
* ������:   
* ��: 
* ����ֵ:   void
* �����б� 	       ��������           		����
*  	       
* �汾��ʷ
*1.0 2020/08/28     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::close()
{
	ManageLog manangeLog;

	deque<deque<string>> dDSLogger = Logger::g_DDSLogger;
	for (int i = 0; i < dDSLogger.size(); i++)
	{
		deque<string> dSLogger = dDSLogger[i];
		for (int j = 0; j < dSLogger.size(); j++)
		{
			manangeLog.DequeToFile(dSLogger);
		}
	}
}
#endif