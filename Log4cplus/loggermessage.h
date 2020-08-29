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
	* ����:     ���ô�ʱLogger��־���ڵĽ��̺�
	* ������:   SetLoggerPid
	* ��:		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	* nLoggerPid 	       int						��ǰ�Ľ���
	* �汾��ʷ
	*1.0 2020/08/29     ��۸�ʵ�ֹ���
	*************************************************************/
	void SetLoggerPid(int nLoggerPid);

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
	* ����:     ���ô�ʱLogger��־���ڵ��̺߳�
	* ������:   SetLoggerTid
	* ��:		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	* nLoggerTid 	       int						��ǰ���߳�
	* �汾��ʷ
	*1.0 2020/08/29     ��۸�ʵ�ֹ���
	*************************************************************/
	void SetLoggerTid(int nLoggerTid);

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
	* ����:     ��ȡLogger��־���ڵĽ��̺�
	* ������:   GetLoggerPid
	* ��:		public
	* ����ֵ:   int m_NLoggerPid: ����logger�Ľ���
	* �����б� 	       ��������           		����	
	*	
	* �汾��ʷ
	*1.0 2020/08/29     ��۸�ʵ�ֹ���
	*************************************************************/
	int GetLoggerPid();

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
	* ����:     ��ȡLogger��־���ڵ��̺߳�
	* ������:   GetLoggerTid
	* ��:		public
	* ����ֵ:   int m_NLoggerPid: ����logger���߳�
	* �����б� 	       ��������           		����
	* 
	* �汾��ʷ
	*1.0 2020/08/29     ��۸�ʵ�ֹ���
	*************************************************************/
	int GetLoggerTid();

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
	string m_StrTime;	// Logger ��־���ɵ�ʱ��
	int m_NProcessId;	// logger ��־����ʱ���ڵĽ���
	string m_StrLoggerRank;	// logger ��־�ĵȼ�
	int m_NThreadId;	//logger ��־�������ڵ��߳�
	string m_StrFileWithLogger;	//logger ��־����ʱ���ڵ��ļ�
	int m_NLineWithLogger;	//logger��־����ʱ���ڵ�����
	string m_StrLoggerContent;	//logger ��־������

};

class LoggerConfig
{

public:
	void SetLoggerFilePath(string strFilePath);

	void SetLoggerNum(int nLoggerFileNum);

	void SetLoggerFileSize(string strLoggerFileSize);

	void SetOutput2LoggerFile(bool bOutput2LoggerFile);

	void SetOutput2Console(bool bOutput2Console);

	string GetLoggerFilePath();

	int GetLoggerNum();

	string GetLoggerFileSize();
	
	bool GetOutput2LoggerFile();

	bool GetOutput2Console();

private:
	string g_StrLoggerFilePath;	//��־�ļ������·��
	int g_NLoggerFileNum;	//��־�ļ�����������
	string g_StrLoggerFileSize;	//��־�ļ������޴�С
	bool g_BOutput2LoggerFile;	//�Ƿ���־������ļ���
	bool g_BOutput2Console;	//�Ƿ���־��Ϣ���������̨
};
#endif
