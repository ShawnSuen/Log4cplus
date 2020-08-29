/*********************************************************************
 *
 *  ��      ��:    loggermessage.cpp
 *
 *  ��Ȩ����:      Shanghai Baosight Software Co., Ltd.
 *
 *  ������	     ���ļ���������LoggerMessage���󣬸ö����а���LoggerMessage��
 *			����ʱ�䣬�ȼ����������ļ��Լ������ڵ�����������logger���������ı�
 *			���������ԡ�ͬʱ�������˶�Ӧ��get��set������
 *      file path:	     C:\Users\Shawn\Desktop\workspace\Log4cplus\Log4cplus
 *  
 *
 *  �汾��ʷ
 *      1.0        2020/08/27    ��۸�      ����
 *
*********************************************************************/
#ifndef LOGGER_MESSAGE_STL
#define LOGGER_MESSAGE_STL

#include <string>

#include "loggermessage.h"

using namespace std;

/*************************************************************
* ����:     ����logger���������ʱ��
* ������:   SetTime
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* strTime 			   string					�����ַ������͵�ʱ�䣬��ʱ����logger��������ʱ��
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void LoggerMessage::SetTime(string strTime)
{
	LoggerMessage::m_StrTime = strTime;
}

/*************************************************************
* ����:     ���ô�ʱLogger��־���ڵĽ��̺�
* ������:   SetLoggerPid
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* nLoggerPid 	       int						��ǰ�Ľ���
* �汾��ʷ
*1.0 2020/08/29     ��۸�ʵ�ֹ���
*************************************************************/
void LoggerMessage::SetLoggerPid(int nLoggerPid)
{
	LoggerMessage::m_NProcessId = nLoggerPid;
}

/*************************************************************
* ����:     ����logger����ĵȼ�
* ������:   SetLoggerRank
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* strLoggerRank 	   string					����logger�ĵȼ�������DEBUG,INFO,WARNING,ERROR
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void LoggerMessage::SetLoggerRank(string strLoggerRank)
{
	LoggerMessage::m_StrLoggerRank = strLoggerRank;
}

/*************************************************************
* ����:     ���ô�ʱLogger��־���ڵĽ��̺�
* ������:   SetLoggerPid
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* nLoggerPid 	       int						��ǰ�Ľ���
* �汾��ʷ
*1.0 2020/08/29     ��۸�ʵ�ֹ���
*************************************************************/
void LoggerMessage::SetLoggerTid(int nLoggerTid)
{
	LoggerMessage::m_NThreadId = nLoggerTid;
}

/*************************************************************
* ����:     ����logger����ʹ�õ��ļ���
* ������:   SetFileWithLogger
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* strFileWithLogger	   string					logger����ʹ�õ��ļ���
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void LoggerMessage::SetFileWithLogger(string strFileWithLogger)
{
	LoggerMessage::m_StrFileWithLogger = strFileWithLogger;
}

/*************************************************************
* ����:     ����logger�������ڵ�����
* ������:   SetLineWithLogger
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* nLineWithLogger    int					����logger�������ڵ�����
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void LoggerMessage::SetLineWithLogger(int nLineWithLogger)
{
	LoggerMessage::m_NLineWithLogger = nLineWithLogger;
}

/*************************************************************
* ����:     ����logger���ı�����
* ������:   SetLoggerCotent
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* strLoggerCotent 	   string					����logger���ı�����
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
void LoggerMessage::SetLoggerCotent(string strLoggerContent)
{
	LoggerMessage::m_StrLoggerContent = strLoggerContent;
}

/*************************************************************
* ����:     ��ȡlogger����ʵ������ʱ��
* ������:   GetTime
* ��:		public
* ����ֵ:   string m_StrTime: logger����ʵ������ʱ��
* �����б� 	       ��������           		����
*
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
string LoggerMessage::GetTime()
{
	return m_StrTime;
}

/*************************************************************
* ����:     ��ȡLogger��־���ڵĽ��̺�
* ������:   SetLoggerPid
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
*
* �汾��ʷ
*1.0 2020/08/29     ��۸�ʵ�ֹ���
*************************************************************/
int LoggerMessage::GetLoggerPid()
{
	return LoggerMessage::m_NProcessId;
}

/*************************************************************
* ����:     ��ȡlogger����ĵȼ�
* ������:   GetLoggerRank
* ��:		public
* ����ֵ:   string m_StrLoggerRank: logger����ĵȼ�
* �����б� 	       ��������           		����
*
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
string LoggerMessage::GetLoggerRank()
{
	return m_StrLoggerRank;
}

/*************************************************************
* ����:     ��ȡ��ʱLogger��־���ڵ��̺߳�
* ������:   SetLoggerTid
* ��:		public
* ����ֵ:   void
* �����б� 	       ��������           		����
* 
* �汾��ʷ
*1.0 2020/08/29     ��۸�ʵ�ֹ���
*************************************************************/
int LoggerMessage::GetLoggerTid() 
{
	return m_NThreadId;
}


/*************************************************************
* ����:     ��ȡlogger����ʵ�������ļ�
* ������:   GetFileWithLogger
* ��:		public
* ����ֵ:   string m_StrFileWithLogger: loggerʵ�������ļ�
* �����б� 	       ��������           		����
*
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
string LoggerMessage::GetFileWithLogger()
{
	return m_StrFileWithLogger;
}

/*************************************************************
* ����:     ��ȡlogger����ʵ����������
* ������:   GetLineWithLogger
* ��:		public
* ����ֵ:   int m_NLineWithLogger: loggerʵ����������
* �����б� 	       ��������           		����
*
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
int LoggerMessage::GetLineWithLogger()
{
	return m_NLineWithLogger;
}

/*************************************************************
* ����:     ��ȡlogger���ı�����
* ������:   GetLoggerContent
* ��:		public
* ����ֵ:   string m_StrLoggerContent: logger���ı�����
* �����б� 	       ��������           		����
*
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
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