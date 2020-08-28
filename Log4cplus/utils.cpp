#ifndef UTILS_STL
#define UTILS_STL

#include <iostream>
#include <string>
#include <vector>
#include <map>

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

#endif