
#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include<iomanip>
#include <sstream>

#include "logger.h"

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
std::string Logger::getLocalTime() {
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