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
void GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent);

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
* 概述:     生成一条Debug日志，包括日志的时间、等级和信息
* 函数名:   Log
* 属		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* pMessage			   char*					输入日志的信息
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void Logger::Debug(char* pLoggerContent)
{
	string strLoggerContent = pLoggerContent;
	GenerateLoggerMessage("Debug", strLoggerContent);
	std::cout << m_LoggerMessage.GetTime() << m_LoggerMessage.GetLoggerRank() <<
		m_LoggerMessage.GetLoggerContent() << std::endl;
	//TODO 需要完成将信息加入到多线程以及写到文件中
}

/*************************************************************
* 概述:     生成一条Info日志，包括日志的时间、等级和信息
* 函数名:   Info
* 属		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* pMessage			   char*					输入日志的信息
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void Logger::Info(char* pLoggerContent)
{
	string strLoggerContent = pLoggerContent;
	GenerateLoggerMessage("Info", strLoggerContent);
	std::cout << m_LoggerMessage.GetTime() << m_LoggerMessage.GetLoggerRank() <<
		m_LoggerMessage.GetLoggerContent() << std::endl;
	//TODO 需要完成将信息加入到多线程以及写到文件中
}

/*************************************************************
* 概述:     生成一条Warning日志，包括日志的时间、等级和信息
* 函数名:   Warning
* 属		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* pMessage			   char*					输入日志的信息
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void Logger::Warning(char* pLoggerContent)
{
	string strLoggerContent = pLoggerContent;
	GenerateLoggerMessage("Warning", strLoggerContent);
	std::cout << m_LoggerMessage.GetTime() << m_LoggerMessage.GetLoggerRank() <<
		m_LoggerMessage.GetLoggerContent() << std::endl;
	//TODO 需要完成将信息加入到多线程以及写到文件中
}

/*************************************************************
* 概述:     生成一条Error日志，包括日志的时间、等级和信息
* 函数名:   Error
* 属		public
* 返回值:   void
* 参数列表： 	       参数类型           		描述
* pMessage			   char*					输入日志的信息
* 版本历史
*1.0 2020/08/27     孙港富实现功能
*************************************************************/
void Logger::Error(char* pLoggerContent)
{
	string strLoggerContent = pLoggerContent;
	GenerateLoggerMessage("Error", strLoggerContent);
	std::cout << m_LoggerMessage.GetTime() << m_LoggerMessage.GetLoggerRank() <<
		m_LoggerMessage.GetLoggerContent() << std::endl;
	//TODO 需要完成将信息加入到多线程以及写到文件中
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