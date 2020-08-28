#ifndef UTILS_INCLUDE
#define UTILS_INCLUDE

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
class Utils
{
public:

	/*************************************************************
	* ����:		�ָ��ַ���
	* ������:	split
	* ��:
	* ����ֵ:   vector<string> result:���طָ����ַ���
	* �����б��� 	       ��������           ����
	* s 				   string			  Ŀ���ַ���
	* seperator			   string			  �ָ���
	* �汾��ʷ
	*1.0 2020/08/21     ��۸�ʵ�ֹ���
	*************************************************************/
	vector<string> Split(const string &s, const string &seperator);

	/*************************************************************
	* ����:     ͬ����ֵ��ȡMap�����ж�Ӧ��ֵ
	* ������:   SearchValueInMap	
	* ��:		public
	* ����ֵ:   string mssTargetMap
	* �����б��� 	       ��������           		����
	* mssTargetMap 	       map<string,string>       �����Ŀ��map����
	* strKey			   string					Ŀ���
	* �汾��ʷ
	*1.0 2020/08/29     ��۸�ʵ�ֹ���
	*************************************************************/
	string SearchValueInMap(map<string, string> mssTargetMap, string strKey);

};
#endif