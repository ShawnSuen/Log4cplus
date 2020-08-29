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
* 概述:     初始化logger
* 函数名:   Init
* 属:
* 返回值:   void
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/28     孙港富实现功能
*************************************************************/
void Logger::InitLogger()
{

	//TODO：设置log是否写入到logger文件中

	//TODO:设置log文件的存储路径

	//TODO:设置log文件的数量上限

	//TODO:设置log文件的大小

	//TODO:设置是否通过控制台输出


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
void Logger::Debug(char* pLoggerContent, int nLine, char* pFileWithLogger)
{
	string strLoggerContent = pLoggerContent;
	string strFileWithLogger = pFileWithLogger;
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Debug", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);
	cout << strLogger << endl;
	//将日志写入到队列里
	g_DSLoggerMessage.push_back(loggerMessage);
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
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Info", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);
	cout << strLogger << endl;
	//将日志写入到队列里
	g_DSLoggerMessage.push_back(loggerMessage);
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
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Warning", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);
	cout << strLogger << endl;
	//将日志写入到队列里
	g_DSLoggerMessage.push_back(loggerMessage);
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
	vector<string> vsFilePath = utils.Split(strFileWithLogger, "\\");
	string strFileName = vsFilePath[vsFilePath.size() - 1];
	LoggerMessage loggerMessage = GenerateLoggerMessage("Error", strLoggerContent, nLine, strFileName);
	string strLogger = Logger2String(loggerMessage);
	cout << strLogger << endl;
	//将日志写入到队列里
	g_DSLoggerMessage.push_back(loggerMessage);
}


#endif