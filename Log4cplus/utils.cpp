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
* 概述:		分割字符串
* 函数名:	split
* 属:
* 返回值:   vector<string> result:返回分割后的字符串
* 参数列表： 	       参数类型           描述
* s 				   string			  目标字符串
* seperator			   string			  分隔符
* 版本历史
*1.0 2020/08/21     孙港富实现功能
*************************************************************/
vector<string> Utils::Split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//找到字符串中首个不等于分隔符的字母；
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

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
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
* 概述:     同过键值获取Map函数中对应的值
* 函数名:   SearchValueInMap
* 属:		public
* 返回值:   string mssTargetMap
* 参数列表： 	       参数类型           		描述
* mssTargetMap 	       map<string,string>       传入的目标map对象
* strKey			   string					目标键
* 版本历史
*1.0 2020/08/29     孙港富实现功能
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
		cout << "map实例中不存在键: " << strKey << endl;
	}
	return strValue;
}

/*************************************************************
* 概述:     获取本地系统时间，精确到毫秒
* 函数名:   GetLocalSystemTime
* 属:		public
* 返回值:   string strLocalTime
* 参数列表： 	       参数类型           		描述
* strLocalTime 	       string					返回本地系统时间
* 版本历史
*1.0 2020/08/27     孙港富实现功能
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
* 概述:     采用冒泡排序算法对vector<string>容器按照字符串进行排序
* 函数名:   SortFileByName
* 属:		public
* 返回值:   vecotr<string> vesTargetVector: 返回已经排序的vector<string>容器
* 参数列表:
* vector<string> vesTargetVector:	传入期望进行排序的目标vector<string>容器
* 版本历史
* 1.0 		2020/08/29     孙港富实现功能
*************************************************************/
vector<string> Utils::SortVectorString(vector<string> vesTargetVector)
{
	for (int nIndex = 0; nIndex < vesTargetVector.size(); nIndex++) {//排列len趟完成排序
		for (int nSubIndex = 0; nSubIndex < vesTargetVector.size() - nIndex - 1; ++nSubIndex) {//每趟排序的元素都从第一个元素开始到尾部没有排序好的元素。第一趟为第一个元素到最后一个元素，排出了最大元素。第二趟为第一个元素到倒数第二个元素(排除以排序好的元素)，排出第二大的元素。
			if (vesTargetVector[nSubIndex] > vesTargetVector[nSubIndex + 1]) {
				swap(vesTargetVector[nSubIndex], vesTargetVector[nSubIndex + 1]);
			}
		}
	}
	return vesTargetVector;
}
#endif