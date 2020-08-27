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

enum eLoggerRank
{
	Debug,
	Info,
	Warning,
	Error
};

class Logger
{

public:
	void Debug();
	void Info();
	void Warining();
	void Error();


private:
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
	std::string GetLocalTime();

	/*************************************************************
	* 概述:     生成一条完整的日志信息，包括日志的时间、等级和信息
	* 函数名:   Log
	* 属		public
	* 返回值:   string strLoggerMessage:返回完整的日志信息包括
	* 参数列表： 	       参数类型           		描述
	* strTime 			   string					输入系统的时间
	* strLoggerRank		   string					输入日志的等级
	* strMessage		   string					输入日志的信息
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/	
	std::string Log(std::string strTime, std::string strLoggerRank, std::string strMessage);

	/*************************************************************
	* 概述:     查找Log文件是否存在
	* 函数名:   FindLogFile
	* 属:		public
	* 返回值:   vector<string> vsLoggerFile:返回查找到的logger文件的路径
	* 参数列表： 	       参数类型           		描述
	* pAddr 			   char *					传入想要查找的文件类型
	* 版本历史
	*1.0 2020/08/27     孙港富实现功能
	*************************************************************/
	std::vector<std::string> FindLogFile(const char* pAddr);
};
#endif
