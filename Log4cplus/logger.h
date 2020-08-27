#ifndef LOGGER_INCLUDE
#define LOGGER_INCLUDE

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "loggermessage.h"

//TODO : 待完成logger日志中，获取logger实例化时所在的文件和行数

class Logger
{

public:

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
	void Debug(char* pMessage);

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
	void Info(char* pMessage);

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
	void Warning(char* pMessage);

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
	void Error(char* pMessage);

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

private:
	LoggerMessage m_LoggerMessage;

	void GenerateLoggerMessage(std::string strLoggerRank, std::string strLoggerContent);
};
#endif
