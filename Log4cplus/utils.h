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
	vector<string> Split(const string &s, const string &seperator);

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
	string SearchValueInMap(map<string, string> mssTargetMap, string strKey);

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
	string GetLocalSystemTime();

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
	vector<string> SortVectorString(vector<string> vesTargetVector);

};
#endif