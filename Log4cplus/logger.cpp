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
#include "threadmanager.h"
#include "ManageLog.h"
ThreadManager threadManager;
ManageLog manageLog;
using namespace std;

/*************************************************************
* 概述:     启动logger的使用。在此方法中包含了读取logger配置文件
*		其中也采用的线程的方式来调用程序。
* 函数名:   Init
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/28     孙港富实现功能
*************************************************************/
void Logger::InitLogger()
{
	//获取LoggerConfig文件
	thread tGetLoggerConfigThread(&ThreadManager::ReadLoggerManager, threadManager);
	tGetLoggerConfigThread.join();

	
}

/*************************************************************
* 概述:     结束logger使用，其中包含了将数据缓存区的logger内容
*		分别写入到logger文件夹、控制台，以及及时清理logger文件
*		保证log文件的数量不会过多。同时生成了三个线程以实现异步
*		的写入和删除，减小对其他线程的影响。
* 函数名:   CloseLogger
* 属:		public	
* 返回值:   void
* 参数列表:
*   	       
* 版本历史
* 1.0 		2020/08/30     孙港富实现功能
*************************************************************/
void Logger::CloseLogger()
{
	thread tWrite2LoggerFileThread(&ThreadManager::WriteLogger2File, threadManager, g_DSLoggerMessage);
	tWrite2LoggerFileThread.join();

	thread tWrite2Console(&ThreadManager::WriteLogger2Console, threadManager, g_DSLoggerMessage);
	tWrite2Console.join();

	thread tClearFileThread(&ThreadManager::ClearLogFile, threadManager);
	tClearFileThread.join();
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
* 概述:     生成一条logger日志
* 函数名:   GenerateLoggerMessage
* 属:		public
* 返回值:   LoggerMessage loggerMessage: 对应属性已经赋值后的logger对象
* 参数列表:
* string strLoggerRank:	log日志的等级
* string strLoggerContent:	log日志的内容
* int nLine: 使用log进行日志记录时，对应语句所在的代码行数
* string strFileWithLogger: 使用log进行日志记录时，对应语句所在的文件名
* 版本历史
* 1.0 		2020/08/30     孙港富实现功能
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
	//将日志写入到队列里
	g_DSLoggerMessage.push_back(strLogger);
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
	//将日志写入到队列里
	g_DSLoggerMessage.push_back(strLogger);
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
	//将日志写入到队列里
	g_DSLoggerMessage.push_back(strLogger);
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
	//将日志写入到队列里
	g_DSLoggerMessage.push_back(strLogger);
}


#endif