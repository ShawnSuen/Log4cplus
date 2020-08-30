#ifndef UTILS_STL
#define UTILS_STL

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <windows.h>

#include "utils.h"

using namespace std;
/*************************************************************
* ����:		�ָ��ַ���
* ������:	split
* ��:
* ����ֵ:   vector<string> result:���طָ����ַ���
* �����б� 	       ��������           ����
* s 				   string			  Ŀ���ַ���
* seperator			   string			  �ָ���
* �汾��ʷ
*1.0 2020/08/21     ��۸�ʵ�ֹ���
*************************************************************/
vector<string> Utils::Split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//�ҵ��ַ������׸������ڷָ�������ĸ��
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}

		//�ҵ���һ���ָ������������ָ���֮����ַ���ȡ����
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}

/*************************************************************
* ����:     ͬ����ֵ��ȡMap�����ж�Ӧ��ֵ
* ������:   SearchValueInMap
* ��:		public
* ����ֵ:   string mssTargetMap
* �����б� 	       ��������           		����
* mssTargetMap 	       map<string,string>       �����Ŀ��map����
* strKey			   string					Ŀ���
* �汾��ʷ
*1.0 2020/08/29     ��۸�ʵ�ֹ���
*************************************************************/
string Utils::SearchValueInMap(map<string, string> mssTargetMap, string strKey)
{
	string strValue;
	if (mssTargetMap.count(strKey))
	{
		
		 strValue = mssTargetMap[strKey];
	}
	else
	{
		strValue = "";
		cout << "mapʵ���в����ڼ�: " << strKey << endl;
	}
	return strValue;
}

/*************************************************************
* ����:     ��ȡ����ϵͳʱ�䣬��ȷ������
* ������:   GetLocalSystemTime
* ��:		public
* ����ֵ:   string strLocalTime
* �����б� 	       ��������           		����
* strLocalTime 	       string					���ر���ϵͳʱ��
* �汾��ʷ
*1.0 2020/08/27     ��۸�ʵ�ֹ���
*************************************************************/
std::string Utils::GetLocalSystemTime() 
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);

	char cLocalTime[34];

	sprintf(cLocalTime,"%4d-%02d-%02d %02d:%02d:%02d:%03d"
		, sys.wYear, sys.wMonth, sys.wDay
		, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);

	string strLcoalTime = cLocalTime;
	return strLcoalTime;
}

/*************************************************************
* ����:     ����ð�������㷨��vector<string>���������ַ�����������
* ������:   SortFileByName
* ��:		public
* ����ֵ:   vecotr<string> vesTargetVector: �����Ѿ������vector<string>����
* �����б�:
* vector<string> vesTargetVector:	�����������������Ŀ��vector<string>����
* �汾��ʷ
* 1.0 		2020/08/29     ��۸�ʵ�ֹ���
*************************************************************/
vector<string> Utils::SortVectorString(vector<string> vesTargetVector)
{
	for (int nIndex = 0; nIndex < vesTargetVector.size(); nIndex++) {//����len���������
		for (int nSubIndex = 0; nSubIndex < vesTargetVector.size() - nIndex - 1; ++nSubIndex) {//ÿ�������Ԫ�ض��ӵ�һ��Ԫ�ؿ�ʼ��β��û������õ�Ԫ�ء���һ��Ϊ��һ��Ԫ�ص����һ��Ԫ�أ��ų������Ԫ�ء��ڶ���Ϊ��һ��Ԫ�ص������ڶ���Ԫ��(�ų�������õ�Ԫ��)���ų��ڶ����Ԫ�ء�
			if (vesTargetVector[nSubIndex] > vesTargetVector[nSubIndex + 1]) {
				swap(vesTargetVector[nSubIndex], vesTargetVector[nSubIndex + 1]);
			}
		}
	}
	return vesTargetVector;
}
#endif