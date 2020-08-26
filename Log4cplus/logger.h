#ifndef LOGGER_INCLUDE
#define LOGGER_INCLUDE

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include<iomanip>
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
	std::string getLocalTime();
};
#endif
