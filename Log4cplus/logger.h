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
	* ����:     ��ȡ����ϵͳʱ��ʱ��
	* ������:   getLocalTime
	* ��:		public
	* ����ֵ:   string strLocalTime
	* �����б� 	       ��������           		����
	* strLocalTime 	       string					���ر���ϵͳʱ��
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/
	std::string getLocalTime();
};
#endif
