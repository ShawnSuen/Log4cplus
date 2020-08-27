#ifndef LOGGER_STL
#define LOGGER_STL

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include<iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <io.h>
#include <process.h>
#include <stdio.h>

#include "logger.h"
#include "loggermessage.h"

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
void GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent);

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
* ����:     ����һ��Debug��־��������־��ʱ�䡢�ȼ�����Ϣ
* ������:   Log
* ��		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* pMessage			   char*					������־����Ϣ
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Debug(char* pLoggerContent)
{
	string strLoggerContent = pLoggerContent;
	GenerateLoggerMessage("Debug", strLoggerContent);
	std::cout << m_LoggerMessage.GetTime() << m_LoggerMessage.GetLoggerRank() <<
		m_LoggerMessage.GetLoggerContent() << std::endl;
	//TODO ��Ҫ��ɽ���Ϣ���뵽���߳��Լ�д���ļ���
}

/*************************************************************
* ����:     ����һ��Info��־��������־��ʱ�䡢�ȼ�����Ϣ
* ������:   Info
* ��		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* pMessage			   char*					������־����Ϣ
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Info(char* pLoggerContent)
{
	string strLoggerContent = pLoggerContent;
	GenerateLoggerMessage("Info", strLoggerContent);
	std::cout << m_LoggerMessage.GetTime() << m_LoggerMessage.GetLoggerRank() <<
		m_LoggerMessage.GetLoggerContent() << std::endl;
	//TODO ��Ҫ��ɽ���Ϣ���뵽���߳��Լ�д���ļ���
}

/*************************************************************
* ����:     ����һ��Warning��־��������־��ʱ�䡢�ȼ�����Ϣ
* ������:   Warning
* ��		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* pMessage			   char*					������־����Ϣ
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Warning(char* pLoggerContent)
{
	string strLoggerContent = pLoggerContent;
	GenerateLoggerMessage("Warning", strLoggerContent);
	std::cout << m_LoggerMessage.GetTime() << m_LoggerMessage.GetLoggerRank() <<
		m_LoggerMessage.GetLoggerContent() << std::endl;
	//TODO ��Ҫ��ɽ���Ϣ���뵽���߳��Լ�д���ļ���
}

/*************************************************************
* ����:     ����һ��Error��־��������־��ʱ�䡢�ȼ�����Ϣ
* ������:   Error
* ��		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* pMessage			   char*					������־����Ϣ
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void Logger::Error(char* pLoggerContent)
{
	string strLoggerContent = pLoggerContent;
	GenerateLoggerMessage("Error", strLoggerContent);
	std::cout << m_LoggerMessage.GetTime() << m_LoggerMessage.GetLoggerRank() <<
		m_LoggerMessage.GetLoggerContent() << std::endl;
	//TODO ��Ҫ��ɽ���Ϣ���뵽���߳��Լ�д���ļ���
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

void Logger::GenerateLoggerMessage(std::string strLoggerRank,std::string strLoggerContent)
{
	m_LoggerMessage.SetTime(GetLocalTime());
	m_LoggerMessage.SetLoggerRank(strLoggerRank);
	m_LoggerMessage.SetLoggerCotent(strLoggerContent);
}

#endif