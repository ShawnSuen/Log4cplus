/*********************************************************************
 *
 *  文      件:    loggermessage.cpp
 *
 *  版权所有:      Shanghai Baosight Software Co., Ltd.
 *
 *  概述：	     本文件中声明了LoggerMessage对象，该对象中包括LoggerMessage的
 *			创建时间，等级，声明的文件以及其所在的行数，还有logger所包含的文本
 *			描述等属性。同时还声明了对应的get和set方法。
 *      file path:	     C:\Users\Shawn\Desktop\workspace\Log4cplus\Log4cplus
 *  
 *
 *  版本历史
 *      1.0        2020/08/27    孙港富      创建
 *
*********************************************************************/
#ifndef LOGGER_MESSAGE_STL
#define LOGGER_MESSAGE_STL

#include <string>

#include "loggermessage.h"

using namespace std;

/*************************************************************
* 概述:     设置logger对象的生成时间
* 函数名:   SetTime
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* strTime 			   string					传入字符串类型的时间，此时间是logger对象编译的时间
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void LoggerMessage::SetTime(string strTime)
{
	LoggerMessage::m_StrTime = strTime;
}

/*************************************************************
* 概述:     设置此时Logger日志所在的进程号
* 函数名:   SetLoggerPid
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* nLoggerPid 	       int						当前的进程
* 版本历史
*1.0 2020/08/29     孙港富实现功能
*************************************************************/
void LoggerMessage::SetLoggerPid(int nLoggerPid)
{
	LoggerMessage::m_NProcessId = nLoggerPid;
}

/*************************************************************
* 概述:     设置logger对象的等级
* 函数名:   SetLoggerRank
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* strLoggerRank 	   string					传入logger的等级，包括DEBUG,INFO,WARNING,ERROR
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void LoggerMessage::SetLoggerRank(string strLoggerRank)
{
	LoggerMessage::m_StrLoggerRank = strLoggerRank;
}

/*************************************************************
* 概述:     设置此时Logger日志所在的进程号
* 函数名:   SetLoggerPid
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* nLoggerPid 	       int						当前的进程
* 版本历史
*1.0 2020/08/29     孙港富实现功能
*************************************************************/
void LoggerMessage::SetLoggerTid(int nLoggerTid)
{
	LoggerMessage::m_NThreadId = nLoggerTid;
}

/*************************************************************
* 概述:     设置logger对象使用的文件名
* 函数名:   SetFileWithLogger
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* strFileWithLogger	   string					logger对象使用的文件名
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void LoggerMessage::SetFileWithLogger(string strFileWithLogger)
{
	LoggerMessage::m_StrFileWithLogger = strFileWithLogger;
}

/*************************************************************
* 概述:     设置logger对象所在的行数
* 函数名:   SetLineWithLogger
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* nLineWithLogger    int					传入logger对象所在的行数
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void LoggerMessage::SetLineWithLogger(int nLineWithLogger)
{
	LoggerMessage::m_NLineWithLogger = nLineWithLogger;
}

/*************************************************************
* 概述:     设置logger的文本内容
* 函数名:   SetLoggerCotent
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* strLoggerCotent 	   string					传入logger的文本内容
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void LoggerMessage::SetLoggerCotent(string strLoggerContent)
{
	LoggerMessage::m_StrLoggerContent = strLoggerContent;
}

/*************************************************************
* 概述:     获取logger对象实例化的时间
* 函数名:   GetTime
* 属:		public
* 返回值:   string m_StrTime: logger对象实例化的时间
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
string LoggerMessage::GetTime()
{
	return m_StrTime;
}

/*************************************************************
* 概述:     获取Logger日志所在的进程号
* 函数名:   SetLoggerPid
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/29     孙港富实现功能
*************************************************************/
int LoggerMessage::GetLoggerPid()
{
	return LoggerMessage::m_NProcessId;
}

/*************************************************************
* 概述:     获取logger对象的等级
* 函数名:   GetLoggerRank
* 属:		public
* 返回值:   string m_StrLoggerRank: logger对象的等级
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
string LoggerMessage::GetLoggerRank()
{
	return m_StrLoggerRank;
}

/*************************************************************
* 概述:     获取此时Logger日志所在的线程号
* 函数名:   SetLoggerTid
* 属:		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* 
* 版本历史
*1.0 2020/08/29     孙港富实现功能
*************************************************************/
int LoggerMessage::GetLoggerTid() 
{
	return m_NThreadId;
}


/*************************************************************
* 概述:     获取logger对象实例化的文件
* 函数名:   GetFileWithLogger
* 属:		public
* 返回值:   string m_StrFileWithLogger: logger实例化的文件
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
string LoggerMessage::GetFileWithLogger()
{
	return m_StrFileWithLogger;
}

/*************************************************************
* 概述:     获取logger对象实例化的行数
* 函数名:   GetLineWithLogger
* 属:		public
* 返回值:   int m_NLineWithLogger: logger实例化的行数
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
int LoggerMessage::GetLineWithLogger()
{
	return m_NLineWithLogger;
}

/*************************************************************
* 概述:     获取logger的文本内容
* 函数名:   GetLoggerContent
* 属:		public
* 返回值:   string m_StrLoggerContent: logger的文本内容
* 参数列表： 	       参数类型           		描述
*
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
string LoggerMessage::GetLoggerContent()
{
	return m_StrLoggerContent;
}


void LoggerConfig::SetLoggerFilePath(string strFilePath)
{
	g_StrLoggerFilePath = strFilePath;
};

void LoggerConfig::SetLoggerNum(int nLoggerFileNum)
{
	g_NLoggerFileNum = nLoggerFileNum;
}

void LoggerConfig::SetLoggerFileSize(string strLoggerFileSize)
{
	g_StrLoggerFileSize = strLoggerFileSize;
}

void LoggerConfig::SetOutput2LoggerFile(bool bOutput2LoggerFile)
{
	g_BOutput2LoggerFile = bOutput2LoggerFile;
}

void LoggerConfig::SetOutput2Console(bool bOutput2Console)
{
	g_BOutput2Console = bOutput2Console;
}

string LoggerConfig::GetLoggerFilePath()
{
	return g_StrLoggerFilePath;
}

int LoggerConfig::GetLoggerNum()
{
	return g_NLoggerFileNum;
}

string LoggerConfig::GetLoggerFileSize()
{
	return g_StrLoggerFileSize;
}

bool LoggerConfig::GetOutput2LoggerFile()
{
	return g_BOutput2LoggerFile;
}

bool LoggerConfig::GetOutput2Console()
{
	return g_BOutput2Console;
}

#endif