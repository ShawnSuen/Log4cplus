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
std::string Logger::GetLocalTime() {
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

std::string Logger::Log(std::string strTime, std::string strLoggerRank, std::string strMessage)
{
	int iPid = (int)_getpid();
	std::string strLoggerMessage = strTime + "|" + strLoggerRank + "|" + std::to_string(iPid)+
		"|"+__FILE__ + ":" + std::to_string(__LINE__) +  strMessage;
	std::cout << strLoggerMessage << std::endl;
	return strLoggerMessage;
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
std::vector<std::string> Logger::FindLogFile(const char* pAddr) {
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

#endif