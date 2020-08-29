#ifndef MANAGELOG_INCLUDE
#define MANAGELOG_INCLUDE
#include <iostream>
#include <string>
#include <queue>
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
	std::string CreateLogFile(string strFilePath);
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
	std::string ClearLogFile(vector<string> vsFileName);


	/*************************************************************
	* ����:     ������CompleteDeque�е���־���ݴ����־�ļ���
	* ������:   DequeToFile
	* ����:     public
	* ����ֵ:   int
	* �����б� 	       ��������           ȡֵ��Χ����
	* CompleteDeque        deque<string>    ʱ�䡢�ȼ�����־����������һ��Ķ���
	* �汾��ʷ
	*1.0  2020/08/28     ������CompleteDeque�е���־���ݴ����־�ļ���
	*************************************************************/
	int DequeToFile(deque<string> CompleteDeque);
	void DefaultPrint(deque<deque<string>> dDSLogger);


	/*************************************************************
	* ����:     ��ȡlog�����ļ���Ĭ�������ļ���·��Ϊ "../log/logconfig.xml"
	* ������:   GetLoggerConfig
	* ��:		public
	* ����ֵ:   void
	* �����б� 	       ��������           		����
	*
	* �汾��ʷ
	*1.0 2020/08/28     ��۸�ʵ�ֹ���
	*************************************************************/
	bool GetLoggerConfig();

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

	void Write2LogFile();
};


#endif