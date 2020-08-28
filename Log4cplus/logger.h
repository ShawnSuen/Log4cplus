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

#include "loggermessage.h"


using namespace std;

class Logger
{

public:
	deque<string> g_DSLogger;
	deque<deque<string>> g_DDSLogger;

	/*************************************************************
	* 概述:     生成一条Debug日志，包括日志的时间、等级和信息
	* 函数名:   Log
	* 属		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* pMessage			   char*					输入日志的信息
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void Debug(char* pMessage,int nLine, char* pFileWithLogger);

	/*************************************************************
	* 概述:     生成一条Info日志，包括日志的时间、等级和信息
	* 函数名:   Log
	* 属		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* pMessage			   char*					输入日志的信息
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void Info(char* pMessage, int nLine, char* pFileWithLogger);

	/*************************************************************
	* 概述:     生成一条Warning日志，包括日志的时间、等级和信息
	* 函数名:   Log
	* 属		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* pMessage			   char*					输入日志的信息
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void Warning(char* pMessage, int nLine, char* pFileWithLogger);

	/*************************************************************
	* 概述:     生成一条Error日志，包括日志的时间、等级和信息
	* 函数名:   Log	
	* 属		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* pMessage			   char*					输入日志的信息
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void Error(char* pMessage, int nLine, char* pFileWithLogger);

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
	std::string Logger2String(LoggerMessage loggerMessage);

	/*************************************************************
	* 概述:     TODO
	* 函数名:   Log	
	* 属		public
	* 返回值:   void
	* 参数列表： 	       参数类型           		描述
	* pMessage			   char*					输入日志的信息
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	void Init();

	void Write2Deque();

	void close();


private:

	LoggerMessage GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent,int nLine, std::string strFileWithLogger);

};
#define DEBUG(message) Debug(message,__LINE__,__FILE__)

#define INFO(message) Info(message,__LINE__,__FILE__)

#define WARNING(message) Warning(message,__LINE__,__FILE__)

#define ERROR(message) Error(message,__LINE__,__FILE__)

#endif


