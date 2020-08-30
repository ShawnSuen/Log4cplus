#ifndef MANAGELOG_INCLUDE
#define MANAGELOG_INCLUDE
#include <iostream>
#include <string>
#include <queue>

#include "loggermessage.h"

using namespace std;
class ManageLog
{
public:
	/*************************************************************
	* ����:    ����log�ļ�
	* ������:   CreateLog
	* ��:	    public
	* ����ֵ:   string
	* �����б� 	       ��������    string      		����
	*
	* �汾��ʷ
	*1.0 2020/08/     ������ʵ�ֹ���
	*1.1 2020/08/29	  ��۸��Ըù��ܽ���������
	*************************************************************/
	string CreateLogFile(string strFilePath);

	/*************************************************************
	* ����:     �����־
	* ������:   ClearLogFile
	* ��:		public
	* ����ֵ:
	* �����б� 	       ��������           		����
	*
	* �汾��ʷ
	*1.0 2020/08/     ������ʵ�ֹ���
	*************************************************************/
	void ClearLogFile(vector<string> vsFileName,int nFileNum);

	/*************************************************************
	* ����:     Ĭ�������ʽ(���������̨)
	* ������:   DefaultPrint
	* ��:		public
	* ����ֵ:   void
	* �����б�:
	* deque<string>  dDSLogger 	 Ŀ�������Logger����
	* �汾��ʷ
	* 1.0 		2020/08/29     ��۸�ʵ�ֹ���
	*************************************************************/
	void DefaultPrint2Console(deque<string> dDSLogger);


	/*************************************************************
	* ����:     ��ȡlog�����ļ���Ĭ�������ļ���·��Ϊ "../log/logconfig.xml"
	* ������:   GetLoggerConfig
	* ��:		public
	* ����ֵ:   LoggerConfig loggerConfig	����LoggerConfig ����
	* �����б� 	       ��������           		����
	*
	* �汾��ʷ
	*1.0 2020/08/28     ��۸�ʵ�ֹ���
	*************************************************************/
	LoggerConfig GetLoggerConfig();

	/*************************************************************
	* ����:     ����Log�ļ���������·�����з���
	* ������:	FindLogFile
	* ��:		public
	* ����ֵ:   vector<string> vsFilePath
	* �����б� 	       ��������           		����
	* strFilePath 	       string					��Ҫ���ҵ��ļ���·��
	* �汾��ʷ
	* 1.0 2020/08/29     ��۸�ʵ�ֹ���
	*************************************************************/
	vector<string> FindLogFile(string strFilePath);

	vector<string> SortFileByName(vector<string> vsFileGroup);

	/*************************************************************
	* ����:     ����������logger����д��logger�ļ���
	* ������:   Write2LogFile
	* ��:		public
	* ����ֵ:   void
	* �����б�:
	* string strFilePath 	       
	* �汾��ʷ
	* 1.0 		2020/08/30     ��۸�ʵ�ֹ���
	*************************************************************/
	void Write2LogFile(string strFilePath,deque<string> dsLoggerMessage);
};


#endif