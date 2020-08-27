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
	* ����:     ��ȡ����ϵͳʱ��ʱ��
	* ������:   getLocalTime
	* ��:		public
	* ����ֵ:   string strLocalTime
	* �����б� 	       ��������           		����
	* strLocalTime 	       string					���ر���ϵͳʱ��
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/
	std::string GetLocalTime();

	/*************************************************************
	* ����:     ����һ����������־��Ϣ��������־��ʱ�䡢�ȼ�����Ϣ
	* ������:   Log
	* ��		public
	* ����ֵ:   string strLoggerMessage:������������־��Ϣ����
	* �����б� 	       ��������           		����
	* strTime 			   string					����ϵͳ��ʱ��
	* strLoggerRank		   string					������־�ĵȼ�
	* strMessage		   string					������־����Ϣ
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/	
	std::string Log(std::string strTime, std::string strLoggerRank, std::string strMessage);

	/*************************************************************
	* ����:     ����Log�ļ��Ƿ����
	* ������:   FindLogFile
	* ��:		public
	* ����ֵ:   vector<string> vsLoggerFile:���ز��ҵ���logger�ļ���·��
	* �����б� 	       ��������           		����
	* pAddr 			   char *					������Ҫ���ҵ��ļ�����
	* �汾��ʷ
	*1.0 2020/08/27     ��۸�ʵ�ֹ���
	*************************************************************/
	std::vector<std::string> FindLogFile(const char* pAddr);
};
#endif
