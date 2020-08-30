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
	deque<string> g_DSLoggerMessage;//定义一个对列，用来缓存数据
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
	void InitLogger();

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
	void CloseLogger();


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


private:
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
	LoggerMessage GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent,int nLine, 
		std::string strFileWithLogger);
};

//定义一条DEBUG宏，实现对Debug方法的调用
#define DEBUG(message) Debug(message,__LINE__,__FILE__)

//定义一条INFO宏，实现对Info方法的调用
#define INFO(message) Info(message,__LINE__,__FILE__)

//定义一条WARNING宏，实现对Warning的调用
#define WARNING(message) Warning(message,__LINE__,__FILE__)

//定义一条ERROR宏，实现对Error的调用
#define ERROR(message) Error(message,__LINE__,__FILE__)

#endif


