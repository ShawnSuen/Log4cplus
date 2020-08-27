#ifndef LOGGER_STL
#define LOGGER_STL

#include <string>
#include <chrono>
#include <iostream>
#include <ctime>
#include<iomanip>
#include <sstream>
#include <string>
#include "logger.h"

/*************************************************************
* ����:     ��ȡ����ϵͳʱ��ʱ��
* ������:   getLocalTime
* ��:		public
* ����ֵ:   string strLocalTime
* �����б� 	       ��������           		����
* strLocalTime 	       string					���ر���ϵͳʱ��
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
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
	std::string strLoggerMessage = strTime + "  [" + strLoggerRank + "]  " + strMessage;
	std::cout << strLoggerMessage << std::endl;
	return strLoggerMessage;
}

#endif