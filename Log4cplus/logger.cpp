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
* 概述:     获取本地系统时间时间
* 函数名:   getLocalTime
* 属:		public
* 返回值:   string strLocalTime
* 参数列表： 	       参数类型           		描述
* strLocalTime 	       string					返回本地系统时间
* 版本历史
*1.0 2020/08/27     孙港富实现功能
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
* 概述:		分割字符串
* 函数名:	split
* 属:
* 返回值:   vector<string> result:返回分割后的字符串
* 参数列表： 	       参数类型           描述
* s 				   string			  目标字符串
* seperator			   string			  分隔符
* 版本历史
*1.0 2020/08/21     孙港富实现功能
*************************************************************/
vector<string> split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//找到字符串中首个不等于分隔符的字母；
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

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
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
* 概述:     将LoggerMessage对象转化成字符串用来加入队列
* 函数名:   Logger2String
* 属:		private
* 返回值:   string strLoggerMessage:LoggerMessage对象转化成的字符串
* 参数列表： 	       参数类型           		描述
* loggerMessage 	   LoggerMessage			传入对应的LoggerMessage对象
* 版本历史
*1.0 2020/08/28     孙港富实现功能
*************************************************************/
std::string Logger::Logger2String(LoggerMessage loggerMessage)
{
	string strLoggerMessage = loggerMessage.GetTime() + "  " + loggerMessage.GetLoggerRank() + "|" +
		loggerMessage.GetFileWithLogger() + ":" + std::to_string(loggerMessage.GetLineWithLogger()) + "  " + loggerMessage.GetLoggerContent();
	return strLoggerMessage;
}

/*************************************************************
* 概述:     实例化Logger对象，完成对Logger对象的属性进行赋值
* 函数名:   GenerateLoggerMessage
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* strLoggerRank 	   string					输入logger的等级
* strLoggerContent	   string					输入logger的内容
* 版本历史
*1.0 2020/08/27     孙港富实现功能
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
* 概述:     生成一条Debug日志，包括日志的时间、等级和信息
* 函数名:   Log
* 属		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* pMessage			   char*					输入日志的信息
* inLine			   int						传入日志使用的行号
* pFileWithLogger	   char*					传入日志使用的名字
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void Logger::Debug(char* pLoggerContent,int nLine,char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Debug", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//将日志写入到队列里
	g_DSLogger.push_back(strLogger);
}
/*************************************************************
* 概述:     生成一条Info日志，包括日志的时间、等级和信息
* 函数名:   Info
* 属		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* pMessage			   char*					输入日志的信息
* inLine			   int						传入日志使用的行号
* pFileWithLogger	   char*					传入日志使用的名字
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void Logger::Info(char* pLoggerContent, int nLine, char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Info", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//将日志写入到队列里
	g_DSLogger.push_back(strLogger);
}

/*************************************************************
* 概述:     生成一条Warning日志，包括日志的时间、等级和信息
* 函数名:   Warning
* 属		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* pMessage			   char*					输入日志的信息
* inLine			   int						传入日志使用的行号
* pFileWithLogger	   char*					传入日志使用的名字
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void Logger::Warning(char* pLoggerContent, int nLine, char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Warning", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//将日志写入到队列里
	g_DSLogger.push_back(strLogger);
}

/*************************************************************
* 概述:     生成一条Error日志，包括日志的时间、等级和信息
* 函数名:   Error
* 属		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* inLine			   int						传入日志使用的行号
* pFileWithLogger	   char*					传入日志使用的名字
* pMessage			   char*					输入日志的信息
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void Logger::Error(char* pLoggerContent, int nLine, char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Error", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);

	//将日志写入到队列里
	g_DSLogger.push_back(strLogger);
}


/*************************************************************
* 概述:     FindLogFile
* 函数名:	FindLogFile
* 属:		public
* 返回值:   string
* 参数列表： 	       参数类型           		描述
* pAddr 			   char *					传入想要查找的文件类型
* 版本历史
*1.0 2020/08/27     孙港富实现功能
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
* 概述:     初始化logger
* 函数名:   Init
* 属: 
* 返回值:   void
* 参数列表： 	       参数类型           		描述
*  	       
* 版本历史
*1.0 2020/08/28     孙港富实现功能
*************************************************************/
void Logger::Init()
{
	Logger::g_DDSLogger = g_ThreadDeque.GetDeque();
	//创建存放队列的队列

}
/*************************************************************
* 概述:     XXXXX
* 函数名:   
* 属: 
* 返回值:   void
* 参数列表： 	       参数类型           		描述
*  	       
* 版本历史
*1.0 2020/08/28     孙港富实现功能
*************************************************************/
void Logger::Write2Deque()
{
	std::thread loggerThread(&ThreadDeque::LoggerPushThread, g_ThreadDeque, g_DSLogger);
	loggerThread.join();
}

/*************************************************************
* 概述:     XXXXX
* 函数名:   
* 属: 
* 返回值:   void
* 参数列表： 	       参数类型           		描述
*  	       
* 版本历史
*1.0 2020/08/28     孙港富实现功能
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