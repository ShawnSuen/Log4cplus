/*********************************************************************
 *
 *  ��      ��:    loggermessage.h
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
#ifndef LOGGER_MESSAGE_INCLUDE
#define LOGGER_MESSAGE_INCLUDE

#include <string>
using namespace std;
class LoggerMessage
{
public:
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
	void SetTime(string strTime);

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
	void SetLoggerRank(string strLoggerRank);
	
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
	void SetFileWithLogger(string strFileWithLogger);

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
	void SetLineWithLogger(int nLineWithLogger);

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
	void SetLoggerCotent(string strLoggerContent);

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
	string GetTime();

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
	string GetLoggerRank();

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
	string GetFileWithLogger();

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
	int GetLineWithLogger();

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
	string GetLoggerContent();

private:
	string m_StrTime;
	string m_StrLoggerRank;
	string m_StrFileWithLogger;
	int m_NLineWithLogger;
	string m_StrLoggerContent;

};
#endif
